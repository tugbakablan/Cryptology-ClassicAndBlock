import hashlib, hmac

key = input("your key is").encode("utf-8")
message = input("your message is").encode("utf-8")

h = hmac.new(key, message, hashlib.sha384)
print("hash hali", h.digest())
print("hexadec hali", h.hexdigest())





