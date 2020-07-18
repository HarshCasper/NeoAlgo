# Importing required library
import hashlib

# Taking string and encoding to utf-8 unicode standard 
str="Hello world".encode('utf-8')

# hasing using md5 method 
# hexdigest will convert bytes to readable hex data
print(hashlib.new('sha256',str).hexdigest())

# OUTPUT '64ec88ca00b268e5ba1a35678a1b5316d212f4f366b2477232534a8aeca37f3c'
