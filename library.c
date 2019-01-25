#include "library.h"
#include "cmark_amalgamation.h"

#include <stdio.h>
#include <tcl.h>

static int
Cmark_Cmd(ClientData cdata, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[])
{
    if(objc!=2) {
        Tcl_WrongNumArgs(interp,1,objv,"markdown");
        return TCL_ERROR;
    }
    int length = 0;
    char * markdown = Tcl_GetStringFromObj(objv[1], &length);
    char * result = cmark_markdown_to_html(markdown, length,0);
    Tcl_SetObjResult(interp, Tcl_NewStringObj(result, -1));
    return TCL_OK;
}

int DLLEXPORT Cmarktcl_Init(Tcl_Interp * interp) {
    if (Tcl_InitStubs(interp, "8.6", 0) == 0) {
        return TCL_ERROR;
    }
    Tcl_CreateObjCommand(interp, "cmark::markdowntohtml",Cmark_Cmd,NULL, NULL);
    Tcl_PkgProvide(interp, PKG_NAME, PKG_VERSION);
    return TCL_OK;
}

