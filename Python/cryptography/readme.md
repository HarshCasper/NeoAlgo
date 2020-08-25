<h1><b>AFFINE CIPHER </b></h1>

<li>The Affine cipher is a type of monoalphabetic substitution cipher which uses a combination of Additive and Multiplicative Ciphers. </li> 
<li>Each letter is enciphered with the function (ax + b) mod 26, where b is the magnitude of the shift. 
<li>The encryption function for a single letter is C=(ax + b) mod 26 where 1≤a≤m, 1≤b≤m where modulus m is the size of the alphabet and a and b are the keys of the cipher. </li>
<li>The value a must be chosen such that a and m are coprime. </li>
<li>The decryption function is P = a-1(c-b)mod m , where a−1 is the modular multiplicative inverse of a modulo m. I.e., it satisfies the equation.</li>


<br>
<hr>
<br>
The above program on affine cipher contains an encryption and decryption functions which takes the plain text and keys as input , checks the conditions and displays the encrypted text as well decrypts it and shows the original plain text again.

 

 

