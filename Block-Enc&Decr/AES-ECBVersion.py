from Crypto.Cipher import AES
import base64

key = input("Enter a 16/24/32 character-length key value")

if len(key) >= 16 and len(key) < 24:
    key = key[:16]
    print("your key is", key[:16])
elif len(key) >= 24 and len(key) < 32:
    key = key[:24]
    print("your key is", key[:24])
elif len(key) >= 32:
    key = key[:32]
    print("your key is", key[:32])
else:
    #raise ValueError("Invalid key length") I don't prefer to start from the scratch
    key = input("Invalid key lenght, enter a 16/24/32 character-lenght key value")

key = key.encode("utf-8")

plaintext = input("Enter your plaintext (ang alphabet)")
plaintext = plaintext.encode("utf-8")

plaintext = plaintext + b' ' * (16 - len(plaintext) % 16)
cipher = AES.new(key, AES.MODE_ECB)
encryptedMessage = cipher.encrypt(plaintext)

print(encryptedMessage)

descryptedMessage = cipher.decrypt(encryptedMessage)
print(descryptedMessage)