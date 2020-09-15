#!/usr/bin/python
# -*- coding: utf-8 -*-


def calculateLps(pattern, lps):

    # length of previous lps

    length = 0
    lps[0] = 0

    iterator = 1
    while iterator < len(pattern):
        if pattern[iterator] == pattern[length]:
            length += 1
            lps[iterator] = length
            iterator += 1
        else:
            if length != 0:

                # iterator is not incremented here

                length = lps[length - 1]
            else:
                lps[iterator] = 0
                iterator += 1


# this is the function used to check if pattern is there in text

def KMPSearch(pattern, text):
    sizePattern = len(pattern)
    sizeText = len(text)

    # lps will hold the longest prefix suffix values for pattern

    lps = [0] * sizePattern
    j = 0

    # this function will calculate the longest prefix suffix

    calculateLps(pattern, lps)

    i = 0
    while i < sizeText:
        if pattern[j] == text[i]:
            i += 1
            j += 1

        if j == sizePattern:
            print('Pattern found at ' + str(i - j + 1))  # print the pattern starting index
            j = lps[j - 1]
        elif i < sizeText and pattern[j] != text[i]:
            if j != 0:
                j = lps[j - 1]
            else:
                i += 1


# for dynamic input use the below code

text = input('Enter the input string : ')
pattern = input('Enter the string to be searched : ')
KMPSearch(pattern, text)

# text = "aaanunaanuaunnanuubhanu"
# pattern = "anu"
# KMPSearch(pattern, text)

# ''' Output
# Pattern found at 3
# Pattern found at 8
# Pattern found at 15
# Pattern found at 21
