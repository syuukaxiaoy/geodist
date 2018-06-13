#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* FIXME: 
   Check these declarations against the C/Fortran source code.
*/

/* .Call calls */
extern SEXP R_haversine(SEXP);
extern SEXP R_haversine_xy(SEXP, SEXP);
extern SEXP R_vincenty(SEXP);
extern SEXP R_vincenty_xy(SEXP, SEXP);

static const R_CallMethodDef CallEntries[] = {
    {"R_haversine",    (DL_FUNC) &R_haversine,    1},
    {"R_haversine_xy", (DL_FUNC) &R_haversine_xy, 2},
    {"R_vincenty",     (DL_FUNC) &R_vincenty,     1},
    {"R_vincenty_xy",  (DL_FUNC) &R_vincenty_xy,  2},
    {NULL, NULL, 0}
};

void R_init_geodist(DllInfo *dll)
{
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
