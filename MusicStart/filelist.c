#include "..\inc\swilib.h"
#include "play_list.h"
#include "rect_patcher.h"

extern char procfile[128];
extern char list_path[128];
//extern int is_new_file_selected;

int file_rtype=0;

typedef struct
{
  void *next;
  int is_folder;
  char *fullname;  
  char *name;  
}FLIST;

typedef struct
{
  void *gui;
  int type;
}FVIEW;

volatile FLIST *fltop;
void Free_FLIST(void)
{
  LockSched();
  FLIST *fl=(FLIST *)fltop;
  fltop=0;
  UnlockSched();
  while(fl)
  {
    FLIST *fl_prev=fl;
    fl=fl->next;
    mfree(fl_prev);
  }
}

enum TYPES {IS_BACK, IS_FOLDER, IS_FILE}; 
const char back[]="..";             

FLIST *AddToFList(const char* full_name, const char *name, int is_folder)
{
  int l_fname;
  FLIST *fl;
  FLIST *fn=malloc(sizeof(FLIST)+(l_fname=strlen(full_name))+strlen(name)+2);
  fn->fullname=(char *)fn+sizeof(FLIST);
  fn->name=(char *)fn+sizeof(FLIST)+l_fname+1;
  strcpy(fn->fullname,full_name);
  strcpy(fn->name,name);
  fn->is_folder=is_folder;
  fn->next=0;
  fl=(FLIST *)fltop;
  if (fl)
  {
    FLIST *pr;
    pr=(FLIST *)&fltop;
    while(strcmp_nocase(fl->name,fn->name)<0)
    {
      pr=fl;
      fl=fl->next;
      if (!fl) break;
    }
    fn->next=fl;
    pr->next=fn;
  }
  else
  {
    fltop=fn;
  }
  return (fn);
}


int FindFiles(char *str, int type)  // type == 0 SelectFolder, type == 1 SelectFile
{
  DIR_ENTRY de;
  unsigned int err;
  char *rev,*s,*d;
  int i, c, n=0;
  char path[256];
  char name[128];
  
  strcpy(path,str);
  Free_FLIST();
  s=path;
  d=name;
  rev=0;
  while((c=*s++))
  {
    *d++=c;
    if (c=='\\' && *s!='\0') rev=d;
  }
  if(rev==0)
    AddToFList("ROOT",back,IS_BACK);
  else
  {
    *rev=0;
    AddToFList(name,back,IS_BACK);
  }
  n++;
  
  
  i=strlen(path);
  path[i++]='*';
  path[i]='\0';
  if (FindFirstFile(&de,path,&err))
  {
    do
    {
      i=strlen(de.folder_name);
      strcpy(path,de.folder_name);
      path[i++]='\\';
      strcpy(path+i,de.file_name);
      if (de.file_attr&FA_DIRECTORY)
      {
        i=strlen(path);
        path[i++]='\\';
        path[i]=0;
        name[0]='\\';
        strcpy(name+1,de.file_name);
        AddToFList(path,name,IS_FOLDER);
        n++;
      }
      else
      {
        if (type!=0)
        {
          AddToFList(path,de.file_name,IS_FILE);
          n++;
        }
      }
    }
    while(FindNextFile(&de,&err));
  }
  FindClose(&de,&err);
  return n;
}


FLIST *FindFLISTtByNS(int *i, int si)
{
  FLIST *fl;
  fl=(FLIST *)fltop;
  while(fl)
  {
    if (fl->is_folder==si)
    {
      if (!(*i)) return (fl);
      (*i)--;
    }    
    fl=fl->next;
  }
  return fl;
}
  
FLIST *FindFLISTtByN(int n)
{
  FLIST *fl;
  fl=FindFLISTtByNS(&n,IS_BACK); if ((!n)&&(fl)) return(fl);
  fl=FindFLISTtByNS(&n,IS_FOLDER); if ((!n)&&(fl)) return(fl);
  fl=FindFLISTtByNS(&n,IS_FILE); if ((!n)&&(fl)) return(fl);
  return fl;
}

void SavePath(FLIST *fl) 
{
  FSTATS fstats;
  unsigned int err;
  if (GetFileStats(fl->fullname,&fstats,&err)!=-1)
  {
    if (file_rtype==0)
      strcpy(procfile, fl->fullname);
    else 
    {
      strcpy(list_path, fl->fullname);
      //ShowMSG(1, (int)list_path);
      load_list(2);
    }
    //is_new_file_selected=1;
  }
}

char header[128];
int filelist_menu_onkey(void *data, GUI_MSG *msg) {
	
  FLIST *fl;
  int i, n;
  i = GetCurMenuItem(data);
  fl = FindFLISTtByN(i);
  
  if (msg->keys == 0x3D || msg->keys == 0x18) 
  {
  	
    if (fl) 
    {
      if (fl->is_folder == IS_FOLDER || fl->is_folder == IS_BACK) 
      {
        int len;
        if (strcmp(fl->fullname, "ROOT")) 
        {
          strncpy(header, fl->fullname, sizeof (header) - 1);
          len = strlen(fl->fullname);
          header[len > sizeof(header) - 1 ? sizeof (header) - 1 : len] = 0;
          n = FindFiles(fl->fullname, 1);
        }
        else 
        {
          int CreateRootMenu();
          n = CreateRootMenu();
        }         
        Menu_SetItemCountDyn(data, n);
        SetCursorToMenuItem(data, 0);
        RefreshGUI();
      }
      else 
      {
      	SavePath(fl);
        return 1;
      }
    }
    //    GeneralFunc_F1(1);
    return -1;
  }
  return 0;
}

void filelist_menu_ghook(void *data, int cmd)
{
  FVIEW *fview=MenuGetUserPointer(data);
  if (cmd==3)
  {
    Free_FLIST();
    mfree(fview);    
  }
  if (cmd==0x0A)
  {
    DisableIDLETMR();
  }
}

void filelist_menu_iconhndl(void *data, int curitem, void *user_pointer)
{
  FLIST *fl;
  WSHDR *ws;
  void *item=AllocMenuItem(data);
  int len;
  fl=FindFLISTtByN(curitem);
  if (fl)
  {
    len=strlen(fl->name);
    ws=AllocMenuWS(data,len+4);
    if (fl->is_folder==IS_BACK || fl->is_folder==IS_FOLDER)
    {
      str_2ws(ws,fl->name,len);
      wsInsertChar(ws,0x0002,1);
      wsInsertChar(ws,0xE008,1);
    }
    else
    {
      str_2ws(ws,fl->name,len);
    }
  }
  else
  {
    ws=AllocMenuWS(data,10);
    wsprintf(ws, "?");
  }
  SetMenuItemText(data, item, ws, curitem);
}

int fmenusoftkeys[]={0,1,2};
SOFTKEY_DESC fmenu_sk[]=
{
  {0x0018,0x0000,(int)"Select"},
  {0x0001,0x0000,(int)"Close"},
  {0x003D,0x0000,(int)"+"}
};

SOFTKEYSTAB fmenu_skt=
{
  fmenu_sk,0
};

HEADER_DESC filelist_HDR={0,0,0,0,NULL,(int)header,LGP_NULL};

MENU_DESC filelist_STRUCT=
{
  8,filelist_menu_onkey,filelist_menu_ghook,NULL,
  fmenusoftkeys,
  &fmenu_skt,
  0x10,
  filelist_menu_iconhndl,
  NULL,   //Items
  NULL,   //Procs
  0   //n
};


int CreateRootMenu()
{
  char path[32];
  unsigned int err;
  int n=0;
  Free_FLIST();
  for (int i=0; i!=5; i++)
  {
    path[0]=i+'0';
    path[1]=':';
    path[2]='\\';
    path[3]=0;
    if (isdir(path,&err))
    {
      AddToFList(path,path,IS_FOLDER);
      n++;
    }
  }
  strcpy(header,"Root");
  return (n);
}



void open_select_file_gui(int type, int file_type)//file_type: 0,music 1,list 
{
  char *s, *rev=0;
  int n, c, len;
  file_rtype=file_type;
  
	if(file_type==0)
	{
	  s = procfile;
    while ((c = *s++)) 
    {
      if (c == '\\' && *s != '\0') rev = s;
    }
    if (!rev)
      n = CreateRootMenu();
    else 
    {
      *rev = 0;
      strncpy(header, procfile, sizeof (header) - 1);
      len = strlen(procfile);
      header[len > sizeof (header) - 1 ? sizeof (header) - 1 : len] = 0;
      n = FindFiles(procfile, type);
    }
  }
	else 
	{
	  s=list_path;
	  
    while ((c = *s++)) 
    {
      if (c == '\\' && *s != '\0') rev = s;
    }
    if (!rev)
      n = CreateRootMenu();
    else 
    {
      *rev = 0;
      strncpy(header, list_path, sizeof (header) - 1);
      len = strlen(list_path);
      header[len > sizeof (header) - 1 ? sizeof (header) - 1 : len] = 0;
      n = FindFiles(list_path, type);
    }
	}
  patch_header(&filelist_HDR);
  CreateMenu(0, 0, &filelist_STRUCT, &filelist_HDR, 0, n, 0, 0);
}

