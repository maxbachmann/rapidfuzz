/* SPDX-License-Identifier: MIT */
/* Copyright © 2020 Max Bachmann */

#pragma once
#include "py_common.hpp"

PyDoc_STRVAR(ratio_docstring,
R"(ratio($module, s1, s2, processor = False, score_cutoff = 0)
--

calculates a simple ratio between two strings

Args:
    s1 (str): first string to compare
    s2 (str): second string to compare
    processor (Union[bool, Callable]): optional callable that reformats the strings.
        None is used by default.
    score_cutoff (float): Optional argument for a score threshold as a float between 0 and 100.
        For ratio < score_cutoff 0 is returned instead. Defaults to 0.

Returns:
    float: ratio between s1 and s2 as a float between 0 and 100

Example:
    >>> fuzz.ratio("this is a test", "this is a test!")
    96.55171966552734
)");
PyObject* ratio(PyObject* /*self*/, PyObject* args, PyObject* keywds);

PyDoc_STRVAR(ratio2_docstring, "");
PyObject* ratio2(PyObject* /*self*/, PyObject* args, PyObject* keywds);

struct CachedRatio : public CachedScorer {
  double call(double score_cutoff) override;
};


PyDoc_STRVAR(partial_ratio_docstring,
R"(partial_ratio($module, s1, s2, processor = False, score_cutoff = 0)
--

calculates the fuzz.ratio of the optimal string alignment

Args:
    s1 (str): first string to compare
    s2 (str): second string to compare
    processor (Union[bool, Callable]): optional callable that reformats the strings.
        None is used by default.
    score_cutoff (float): Optional argument for a score threshold as a float between 0 and 100.
        For ratio < score_cutoff 0 is returned instead. Defaults to 0.

Returns:
    float: ratio between s1 and s2 as a float between 0 and 100

Example:
    >>> fuzz.partial_ratio("this is a test", "this is a test!")
    100
)");
PyObject* partial_ratio(PyObject* /*self*/, PyObject* args, PyObject* keywds);

struct CachedPartialRatio : public CachedScorer {
  double call(double score_cutoff) override;
};


PyDoc_STRVAR(token_sort_ratio_docstring,
R"(token_sort_ratio($module, s1, s2, processor = False, score_cutoff = 0)
--

sorts the words in the strings and calculates the fuzz.ratio between them

Args:
    s1 (str): first string to compare
    s2 (str): second string to compare
    processor (Union[bool, Callable]): optional callable that reformats the strings.
        utils.default_process is used by default, which lowercases the strings and trims whitespace
    score_cutoff (float): Optional argument for a score threshold as a float between 0 and 100.
        For ratio < score_cutoff 0 is returned instead. Defaults to 0.

Returns:
    float: ratio between s1 and s2 as a float between 0 and 100

Example:
    >>> fuzz.token_sort_ratio("fuzzy wuzzy was a bear", "wuzzy fuzzy was a bear")
    100.0
)");
PyObject* token_sort_ratio(PyObject* /*self*/, PyObject* args, PyObject* keywds);

struct CachedTokenSortRatio : public CachedScorer {
  void str1_set(python_string str) override;
  void str2_set(python_string str) override;
  double call(double score_cutoff) override;
};


PyDoc_STRVAR(partial_token_sort_ratio_docstring,
R"(partial_token_sort_ratio($module, s1, s2, processor = False, score_cutoff = 0)
--

sorts the words in the strings and calculates the fuzz.partial_ratio between them

Args:
    s1 (str): first string to compare
    s2 (str): second string to compare
    processor (Union[bool, Callable]): optional callable that reformats the strings.
        utils.default_process is used by default, which lowercases the strings and trims whitespace
    score_cutoff (float): Optional argument for a score threshold as a float between 0 and 100.
        For ratio < score_cutoff 0 is returned instead. Defaults to 0.

Returns:
    float: ratio between s1 and s2 as a float between 0 and 100
)");
PyObject* partial_token_sort_ratio(PyObject* /*self*/, PyObject* args, PyObject* keywds);

struct CachedPartialTokenSortRatio : public CachedScorer {
  void str1_set(python_string str) override;
  void str2_set(python_string str) override;
  double call(double score_cutoff) override;
};


PyDoc_STRVAR(token_set_ratio_docstring,
R"(token_set_ratio($module, s1, s2, processor = False, score_cutoff = 0)
--

Compares the words in the strings based on unique and common words between them
using fuzz.ratio

Args:
    s1 (str): first string to compare
    s2 (str): second string to compare
    processor (Union[bool, Callable]): optional callable that reformats the strings.
        utils.default_process is used by default, which lowercases the strings and trims whitespace
    score_cutoff (float): Optional argument for a score threshold as a float between 0 and 100.
        For ratio < score_cutoff 0 is returned instead. Defaults to 0.

Returns:
    float: ratio between s1 and s2 as a float between 0 and 100

Example:
    >>> fuzz.token_sort_ratio("fuzzy was a bear", "fuzzy fuzzy was a bear")
    83.8709716796875
    >>> fuzz.token_set_ratio("fuzzy was a bear", "fuzzy fuzzy was a bear")
    100.0
)");
PyObject* token_set_ratio(PyObject* /*self*/, PyObject* args, PyObject* keywds);

struct CachedTokenSetRatio : public CachedScorer {
  double call(double score_cutoff) override;
};


PyDoc_STRVAR(partial_token_set_ratio_docstring,
R"(partial_token_set_ratio($module, s1, s2, processor = False, score_cutoff = 0)
--

Compares the words in the strings based on unique and common words between them
using fuzz.partial_ratio

Args:
    s1 (str): first string to compare
    s2 (str): second string to compare
    processor (Union[bool, Callable]): optional callable that reformats the strings.
        utils.default_process is used by default, which lowercases the strings and trims whitespace
    score_cutoff (float): Optional argument for a score threshold as a float between 0 and 100.
        For ratio < score_cutoff 0 is returned instead. Defaults to 0.

Returns:
    float: ratio between s1 and s2 as a float between 0 and 100
)");
PyObject* partial_token_set_ratio(PyObject* /*self*/, PyObject* args, PyObject* keywds);

struct CachedPartialTokenSetRatio : public CachedScorer {
  double call(double score_cutoff) override;
};


PyDoc_STRVAR(token_ratio_docstring,
R"(token_ratio($module, s1, s2, processor = False, score_cutoff = 0)
--

Helper method that returns the maximum of fuzz.token_set_ratio and fuzz.token_sort_ratio
    (faster than manually executing the two functions)

Args:
    s1 (str): first string to compare
    s2 (str): second string to compare
    processor (Union[bool, Callable]): optional callable that reformats the strings.
        utils.default_process is used by default, which lowercases the strings and trims whitespace
    score_cutoff (float): Optional argument for a score threshold as a float between 0 and 100.
        For ratio < score_cutoff 0 is returned instead. Defaults to 0.

Returns:
    float: ratio between s1 and s2 as a float between 0 and 100
)");
PyObject* token_ratio(PyObject* /*self*/, PyObject* args, PyObject* keywds);

struct CachedTokenRatio : public CachedScorer {
  double call(double score_cutoff) override;
};


PyDoc_STRVAR(partial_token_ratio_docstring,
R"(partial_token_ratio($module, s1, s2, processor = False, score_cutoff = 0)
--

Helper method that returns the maximum of fuzz.partial_token_set_ratio and
fuzz.partial_token_sort_ratio (faster than manually executing the two functions)

Args:
    s1 (str): first string to compare
    s2 (str): second string to compare
    processor (Union[bool, Callable]): optional callable that reformats the strings.
        utils.default_process is used by default, which lowercases the strings and trims whitespace
    score_cutoff (float): Optional argument for a score threshold as a float between 0 and 100.
        For ratio < score_cutoff 0 is returned instead. Defaults to 0.

Returns:
    float: ratio between s1 and s2 as a float between 0 and 100
)");
PyObject* partial_token_ratio(PyObject* /*self*/, PyObject* args, PyObject* keywds);

struct CachedPartialTokenRatio : public CachedScorer {
  double call(double score_cutoff) override;
};


PyDoc_STRVAR(WRatio_docstring,
R"(WRatio($module, s1, s2, processor = False, score_cutoff = 0)
--

Calculates a weighted ratio based on the other ratio algorithms

Args:
    s1 (str): first string to compare
    s2 (str): second string to compare
    processor (Union[bool, Callable]): optional callable that reformats the strings.
        utils.default_process is used by default, which lowercases the strings and trims whitespace
    score_cutoff (float): Optional argument for a score threshold as a float between 0 and 100.
        For ratio < score_cutoff 0 is returned instead. Defaults to 0.

Returns:
    float: ratio between s1 and s2 as a float between 0 and 100
)");
PyObject* WRatio(PyObject* /*self*/, PyObject* args, PyObject* keywds);

struct CachedWRatio : public CachedScorer {
  double call(double score_cutoff) override;
};


PyDoc_STRVAR(QRatio_docstring,
R"(QRatio($module, s1, s2, processor = False, score_cutoff = 0)
--

Calculates a quick ratio between two strings using fuzz.ratio

Args:
    s1 (str): first string to compare
    s2 (str): second string to compare
    processor (Union[bool, Callable]): optional callable that reformats the strings.
        utils.default_process is used by default, which lowercases the strings and trims whitespace
    score_cutoff (float): Optional argument for a score threshold as a float between 0 and 100.
        For ratio < score_cutoff 0 is returned instead. Defaults to 0.

Returns:
    float: ratio between s1 and s2 as a float between 0 and 100

Example:
    >>> fuzz.QRatio("this is a test", "this is a test!")
    96.55171966552734
)");
PyObject* QRatio(PyObject* /*self*/, PyObject* args, PyObject* keywds);

struct CachedQRatio : public CachedScorer {
  double call(double score_cutoff) override;
};