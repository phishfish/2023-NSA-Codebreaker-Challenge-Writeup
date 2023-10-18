import itertools
import hashlib
import string

base_string = "briefframe"
characters = string.ascii_lowercase + string.digits + string.punctuation
# Generate all combinations
combinations = [''.join(p) for p in itertools.product(characters, repeat=3)]

# Create a list of strings to hash
strings_to_hash = [base_string + s for s in combinations]

# Hash and save to a file
with open("wordlist.txt", "w") as f:
    for string in strings_to_hash:
        sha1_hash = hashlib.sha1(string.encode()).hexdigest()
        f.write(sha1_hash + '\n')
