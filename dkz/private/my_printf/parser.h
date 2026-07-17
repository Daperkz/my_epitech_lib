/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** parser
*/
/**
** @file parser.h
** @brief Tokenizer and parsing handler for the my_printf formatting engine.
**
** @internal
** This header contains the core parsing loop logic, analyzing format
** specifiers, parsing width/precision parameters, handling modifiers,
** and routing output to standard file descriptors
** or dynamically allocated strings.
**
** @author Daperkz
** @ingroup libdkz
** @test ./test/src/printf/parser/
** @version 1.1
** @date 2026-07-17
*/

#ifndef DKZ_PRINTF_PARSER_H_
    #define DKZ_PRINTF_PARSER_H_

    #include "internal.h"

/*
** -_-
** PARSING & DISPATCH ENGINE
** -_-
*/

/**
** @brief Parses a single conversion specifier and executes
** its formatting chain.
**
** @internal
** Evaluates formatting flags (`-`, `+`, ` `, `#`, `0`),
** processes width/precision
** (supporting positional `*` arguments via `va_arg`), and dispatches conversion
** tasks. Finally, it executes standard modifier post-processing (precision,
** sharp flag, sign flags, and width aligning) before committing output.
**
** @note **Output Routing Behavior:**
** - If @p ctx->fd is not -1, outputs are printed directly
** to the file descriptor,
**   and @p ctx->count is updated with the bytes written.
** - If @p ctx->fd is -1, the output is appended to the heap-allocated string
**   tracked by @p str_ptr (mimicking `sprintf` behaviour).
**
** @param[in, out] ctx Pointer to the active engine printing context.
** @param[in] format Pointer to the format string offset (starting after `%`).
** @param[in, out] args The argument list containing values to format.
** @param[in, out] str_ptr Address of the output string pointer used when
** buffering to memory (@p ctx->fd == -1).
**
** @return @b int The total characters consumed from the @p format string
** (offset + 1) to skip past the format sequence.
** @retval 0 Returned if the conversion specifier character does not match
** any known flags in the dispatch table.
** @retval -1 Returned if post-processing fails, if memory allocation fails,
** or if a write syscall returns an error.
**/
int handle_conversion(
    pf_ctx_t *ctx, const char *format, va_list args, char **str_ptr
);

#endif /* !DKZ_PRINTF_PARSER_H_ */
