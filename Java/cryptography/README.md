AFFINE CIPHER :-
	It is one of the methods from cryptography.

	Algorithm :- 
		1) Input text
		2) Find numeric value associated with each letter in the text as "A as 0", "B as 1",..."a as 26", ... etc.
		3) Apply the encryption or decryption formula according to the given instructions.
		4) Now you will get a numeric value, find its equivalent letter (described in step 2).
		5) Collect all the letters and form the cipher text.
		6) Display Cipher text.

	The Encryption and Decryption formula's followed by the Affine Cipher are as follows :

		Encryption :-
			cipherCode = ((multiplicationFactor * inputCode) + additionFactor) % lengthOfAlphabets

		Decrytion :-
			decipherCode = ((inverse_multiplicationFactor) * (inputCode - additionFactor)) % lengthOfAlphabets
 
		Symbols :-
		1) Length of the alphabet list => 
				It is the total no. of alphabets used as a dictionary to encrypt or decrypt the text.
				In this case, we are considering english language so the dictionary has "A to Z" and "a to z"

		2) Multiplication Factor => 
				It is a multiplication factor to the input code. It should be coprime with z to work this algorithm.
				In this case, we will be randomly choosing 'multiplication factor' from the set of coprime no.s to length of alphabets.

		3) Inverse of Multiplication Factor => 	
				This is the a-inverse i.e. the multiplicative inverse of a with respect to length of alphabets. 
				Means (Multiplication Factor x Inverse Multiplication Factor) mod length of alphabets = 1.
 
		4) Addition Factor => 
				It is a addition factor. There are no specific constraints other than 0 <= Addition Factor <= Length of alphabets.

