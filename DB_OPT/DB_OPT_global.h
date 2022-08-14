#ifndef DB_OPT_GLOBAL_H
#define DB_OPT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DB_OPT_LIBRARY)
#  define DB_OPT_EXPORT Q_DECL_EXPORT
#else
#  define DB_OPT_EXPORT Q_DECL_IMPORT
#endif

#endif // DB_OPT_GLOBAL_H
