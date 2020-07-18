# Importing required library
import hashlib

# Taking string and encoding to utf-8 unicode standard 
str="Hello world".encode('utf-8')

# hasing using md5 method 
# hexdigest will convert bytes to readable hex data
print(hashlib.new('md5',str).hexdigest())

# OUTPUT '3e25960a79dbc69b674cd4ec67a72c62'
