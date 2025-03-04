/**
 * Copyright (c) 2016 rxi
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the MIT license. See `ini_rw.c` for details.
 */

#ifndef INI_RW_H
#define INI_RW_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h>

#define INI_RW_VERSION "0.1.3"

typedef struct ini_t ini_t;

ini_t*      ini_load(const char *filename);
ini_t*      ini_create(const char *data, const size_t sz);
int         ini_save(const ini_t *ini, const char *filename);
char*       ini_tostring(const ini_t *ini); // Call free() on the returned string when done with the returned string.
int         ini_merge(ini_t *dst, const ini_t *src); // Copies entries from src to dst, overwriting entries in dst that already existed.
ini_t*      ini_copy(const ini_t *ini);
void        ini_free(ini_t *ini);
const char* ini_get(const ini_t *ini, const char *section, const char *key);
int         ini_sget(const ini_t *ini, const char *section, const char *key, const char *scanfmt, ...); // Returns the number of fields successfully read or EOF if there was an error in processing.
int         ini_set(ini_t *ini, const char *section, const char *key, const char *val); // If you set a key to NULL or an empty string, it's deleted from the INI.
int         ini_pset(ini_t *ini, const char *section, const char *key, const char *printfmt, ...);
int         ini_erase(ini_t *ini, const char *section, const char **keys, const size_t n); // Call with NULL section to erase all sections, call with a section and NULL keys to erase that section, call with a section and array of keys with n the number of keys in the array to erase only those keys.

#ifdef __cplusplus
}
#endif

#endif
