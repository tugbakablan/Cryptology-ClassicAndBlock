import hashlib, binascii
from Crypto.Hash import keccak

message = input("enter your text ").encode("utf-8")

sha224_hash = hashlib.sha224(message).digest()
print("a) SHA-224 =", binascii.hexlify(sha224_hash).decode())

sha3_256_hash = hashlib.sha3_256(message).digest()
print("b) SHA3-256 =", binascii.hexlify(sha3_256_hash).decode())

sha3_224_hash = hashlib.sha3_224(message).digest()
print("c) SHA3-224 =", binascii.hexlify(sha3_224_hash).decode())

sha3_384_hash = hashlib.sha3_384(message).digest()
print("d) SHA3-384 =", binascii.hexlify(sha3_384_hash).decode())

k = keccak.new(digest_bits=384)
k.update(message)
print("e) Keccak-384 =", k.hexdigest())

sha512_hash = hashlib.sha512(message).digest()
print("f) Whirlpool-512/using SHA-512 =", binascii.hexlify(sha512_hash).decode())