/* QIO_close_read.c */

#include <qio_config.h>
#include <qio.h>
#include <qio_string.h>
#include <lrl.h>
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif
#ifdef HAVE_MALLOC_H
#include <malloc.h>
#endif

int QIO_close_read(QIO_Reader *in){
  int status;

  if(!in)return QIO_SUCCESS;
  status = LRL_close_read_file(in->lrl_file_in);
  if(in->layout)free(in->layout->latsize);
  free(in->layout);
  DML_free_sitelist(in->sites);
  QIO_string_destroy(in->xml_record);
  free(in);
  if(status != LRL_SUCCESS)return QIO_ERR_CLOSE;
  return QIO_SUCCESS;
}
