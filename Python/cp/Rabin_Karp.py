"""
    Rabin-Karp or Karp-Robin is an pattern matching algorithm with  average case and best case complexity O(m + n) and the worst case complexity  O(mn), it is most efficient when  used with multiple patterns
    as it is able to check if any of a set of patterns match a section of text in O(1)
    given the precomputed hashes.
"""
# Numbers of alphabet which we call base
alphabet_size = 256


def rabin_karp(pattern, text, modulus=1000003):

    M = len(pattern)
    N = len(text)
    i = 0
    j = 0
    pattern_hash = 0
    text_hash = 0
    h = 1
    no_of_matches = 0

    for i in range(M-1):
        h = (h*alphabet_size) % modulus

    # Calculate the hash values of pattern and text

    for i in range(M):
        pattern_hash = (alphabet_size*pattern_hash + ord(pattern[i])) % modulus
        text_hash = (alphabet_size*text_hash + ord(text[i])) % modulus

    # Slide the pattern over text one by one
    for i in range(N-M+1):

        if pattern_hash == text_hash:

            for j in range(M):
                if text[i+j] != pattern[j]:
                    break

            j += 1

            if j == M:
                print(f"Pattern found at index {i}")
                no_of_matches += 1

        if i < N-M:
            text_hash = (alphabet_size*(text_hash -
                                        ord(text[i])*h) + ord(text[i+M])) % modulus

            if text_hash < 0:
                text_hash = text_hash+modulus

    if no_of_matches == 0:
        print("No matches found for the given pattern")
    elif no_of_matches == 1:
        print("Only one match found for the given pattern")
    else:
        print(
            f"There are {no_of_matches} matches for the pattern in the text ")


def main():

    text = input("Enter the text: ")
    pattern = input("Enter the pattern: ")
    rabin_karp(pattern, text)


main()
