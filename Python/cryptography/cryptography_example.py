from base64 import b64decode,b64encode
from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP

#Setting Public and Private keys, use ras_keygen.py to generate keys
PRIV = 'rsa_priv.pem'
PUB = 'rsa_pub.pem'

#Function for encryption
def enc(x):
	f1 = open(PUB, 'rb')
	pubKey = RSA.importKey(f1.read())
	cipher = PKCS1_OAEP.new(pubKey)
	return cipher.encrypt(x.encode("utf-8"))

#Function for decryption
def dec(enc):
	f = open(PRIV, 'rb')
	key = RSA.importKey(f.read())
	decipher = PKCS1_OAEP.new(key)  
	return decipher.decrypt(enc)

#driver function
def main():
	x = "This is the secret text"
	print("\nSecret text : \n", x)
	encrypted = enc(x)
	print("\nEncrypted text: \n", b64encode(encrypted).decode("utf-8"))
	decrypted = dec(encrypted)
	print("\nDecrypted text: \n", decrypted.decode("utf-8"))

#calling main
if __name__ == '__main__':
	main()