/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** config
*/
/**
** @file config.h
** @brief Header file for configuration file parsing and hashtable-backed
** storage.
**
** This file contains the definitions, macros, and structures for the libdkz
** configuration module, allowing quick key-value lookups from parsed files.
**
** @author Daperkz
** @ingroup libdkz
** @test ./test/src/config/
** @version 1.0
** @date 2026-07-16
*/

#ifndef DKZ_CONFIG_H_
    #define DKZ_CONFIG_H_

    #include "hashtable.h"
    #include "utils.h"
    #include "string.h"

    /**
    ** @brief Default size for the internal configuration hashtable buckets
    **/
    #define CONFIG_DEFAULT_SIZE 50

    /**
    ** @brief Retrieves a raw string value from the configuration using a key
    **
    ** @param conf The configuration hashtable pointer (@b config_t*)
    ** @param key The unique key identifier string to search for (@b char*)
    **
    ** @return @b char* Pointer to the value, or NULL if the key is not found.
    **/
    #define CONFIG_GET(conf, key) ht_get(conf, key)

    /**
    ** @brief Retrieves an integer representation of a configuration value
    **
    ** @param conf The configuration hashtable pointer (@b config_t*)
    ** @param key The unique key identifier string to search for (@b char*)
    **
    ** @return @b int The converted integer value.
    ** @retval 0 Returned if the key is not found or the value is invalid.
    **/
    #define CONFIG_GET_INT(conf, key) my_atoi(ht_get(conf, key))

    /**
    ** @brief Retrieves a double/float representation of a configuration value
    **
    ** @param conf The configuration hashtable pointer (@b config_t*)
    ** @param key The unique key identifier string to search for (@b char*)
    **
    ** @return @b double The converted double precision float value.
    ** @retval 0.0 Returned if the key is not found or the value is invalid.
    **/
    #define CONFIG_GET_FLOAT(conf, key) my_atof(ht_get(conf, key))

    /**
    ** @brief Dumps the key-value pairs stored in the configuration to stdout
    **
    ** @param conf The configuration hashtable pointer (@b config_t*)
    **
    ** @return @b void
    **/
    #define CONFIG_DUMP(conf) ht_dump(conf, my_putstr)

    /**
    ** @brief Destroys the configuration, freeing all stored keys and values
    **
    ** @param conf The configuration hashtable pointer (@b config_t*)
    **
    ** @return @b void
    **/
    #define CONFIG_DESTROY(conf) ht_destroy(conf, free)


/**
** @brief Type definition representing the configuration
** (implemented as a hashtable).
**/
typedef ht_t config_t;

/**
** @brief Reads a file to output a hashtable of all the values found
**
** This function parses a key-value file where elements are separated by '='.
** Whitespaces around keys and values are automatically trimmed. Any lines
** starting with '#' or ';' are ignored as comments.
**
** @param[in] filepath Path to the configuration file to load and parse.
** @param[in] size The bucket size of the internal hashtable structure.
**
** @return @b config_t* An allocated configuration hashtable structure.
** @retval NULL Returned if @p filepath is NULL, the file cannot be read,
** or if a memory allocation failure occurs during runtime.
**
** @note Example file structure:
** # This is a comment\\n
** PORT = 8080\\n
** HOST = 127.0.0.1\\n\\0
**/
config_t *config_create(char const *filepath, int size);


#endif /* !DKZ_CONFIG_H_ */
