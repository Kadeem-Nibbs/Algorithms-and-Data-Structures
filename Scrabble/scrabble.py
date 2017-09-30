import re

ALPHABET = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
VOWELS = ['A', 'E', 'I', 'O', 'U', 'Y']

word_list = []

f = "words.txt"

word_file = open(f, 'r')

for line in word_file:
    word = line.strip()
    word_list.append(word)

word_file.close()

def has_uu(word):
    """
    Returns True if the input word contains two or more consecutive u's,
    returns False otherwise.

    """
    if "UU" in word:
        return True
    else:
        return False

def find_words_with_uu(word_list):
    """
    Returns the a list of the words in word_list that contain two or more
    consecutive u's.

    """
    words_with_uu = [word for word in word_list if has_uu(word)]]
    return words_with_uu

def find_letters_not_doubled(word_list):
    """
    Finds the letters in the alphabet that do not appear consecutively in
    the input word_list.

    Parameters:
    -----------
    word_list: list of strings
        Words to check for appearance of consecutive identical letters.

    Returns:
    --------
    remaining_letters: list of single-character strings with no duplicates
        Letters in the alphabet that do not appear consecutively in any word
        in the input word_list.

    """
    remaining_letters = ALPHABET[:]
    for word in word_list:
        if not remaining_letters:
            return remaining_letters
        for letter in remaining_letters:
            match_string = letter * 2
            if match_string in word:
                remaining_letters.remove(letter)
    return remaining_letters

def longest_palindrome(word_list):
    """
    Finds the longest palindrome in the input word_list.

    Parameters:
    -----------
    word_list: list of strings
        Words to check for appearance of consecutive identical letters.

    Returns:
    --------
    longest_palindrome: string
        The longest palindrome in the input word_list.

    """
    longest_palindrome = ""
    for word in word_list:
        if word == word[::-1]:
            if len(word) > len(longest_palindrome):
                longest_palindrome = word
    return longest_palindrome

def has_all_vowels_in_order(word):
    """
    Returns match object if the input word contains every vowel (including y),
    and each vowel occurs in alphabetical order.

    Parameters:
    -----------
    word: string
        Word to check for presence and ordering of vowels.

    """
    vowels = ['A', 'E', 'I', 'O', 'U', 'Y']
    for vowel in vowels:
        if vowel not in word:
            return False
    regex_string = r'^[^%s]*[^%s]*[^%s]*[^%s]*[^%s]*[^%s]*$'
    match_sections = []
    for vowel in vowels:
        vowels_to_avoid = vowels[:]
        vowels_to_avoid.remove(vowel)
        match_section = "".join(vowels_to_avoid)
        match_sections.append(match_section)
    match_sections = tuple(match_sections)
    regex_string = regex_string % match_sections
    return re.match(regex_string, word)

def find_words_with_all_vowels_in_order(word_list):
    """
    Finds all of the words in the input_word list where all of the vowels
    appear in alphabetical order.

    Parameters:
    -----------
    word_list: list of strings
        List of words to check for appearance and ordering of vowels.

    Returns:
    --------
    matching_words: list of strings
        List of words where all vowels appear in alphabetical order.

    """
    matching_words = []
    for word in word_list:
        if has_all_vowels_in_order(word):
            matching_words.append(word)
    return matching_words

def has_all_vowels(word):
    """
    Returns match object if the input word contains every vowel (including y).

    Parameters:
    -----------
    word: string
        Word to check for presence of vowels.

    """
    for vowel in VOWELS:
        if vowel not in word:
            return False
    return True

def find_words_with_all_vowels(word_list):
    """
    Finds all of the words in the input_word list where all of the vowels
    appear.

    Parameters:
    -----------
    word_list: list of strings
        List of words to check for appearanceof vowels.

    Returns:
    --------
    matching_words: list of strings
        List of words where all vowels appear.

    """
    matching_words = []
    for word in word_list:
        if has_all_vowels(word):
            matching_words.append(word)
    return matching_words

def letter_with_most_appearances_in_word(word_list):
    """
    Finds the letter that has the most appearances in a single word.

    Parameters:
    -----------
    word_list: list of strings
        List of words to check for appearance of vowels.

    Returns:
    --------
    word: string
        Word that contains most occurences of a single letter.
    letter_with_most_appearances: single-character string
        Letter that appears the most times in a single word.
    num_appearances: int
        Number of appearances of the letter that appears the most times in a

    """
    letter_with_most_appearances = None
    num_appearances = 0
    word = ""
    for w in word_list:
        letter_counts = [(letter, w.count(letter)) for letter in set(w)]
        max_letter_and_count = max(letter_counts, key=lambda x: x[1])
        most_common_letter, count = max_letter_and_count
        if count > num_appearances:
            num_appearances = count
            letter_with_most_appearances = most_common_letter
            word = w
    return (word, letter_with_most_appearances, num_appearances)

def find_longest_anagrams(word_list):
    """
    Finds the longest anagrams in a list of words, by sorting the words into
    bins (a dictionary) by length and comparing the character counts of every
    word in the bin with each other.

    Parameters:
    -----------
    word_list: string
        List to search for anagrams.

    Returns:
    --------
    longest_anagrams: list of list of strings
        Each inner list contains strings that are anagrams of each other.

    """
    word_dict = {}
    longest_anagrams = None
    longest_anagram_length = 0
    for word in word_list:
        length = len(word)
        if not word_dict.get(length):
            word_dict[length] = [word]
        else:
            word_dict[length].append(word)
    for word in word_list:
        length = len(word)
        if length < longest_anagram_length:
            continue
        word_letter_count = {letter: word.count(letter) for letter in set(word)}
        anagrams = [word]
        word_dict[length].remove(word)
        for w in word_dict[length]:
            w_letter_count = {letter: w.count(letter) for letter in set(w)}
            if word_letter_count == w_letter_count:
                anagrams.append(w)
        if len(anagrams) == 1:
            continue
        if length == longest_anagram_length:
            longest_anagrams.append(anagrams)
        else:
            longest_anagrams = [anagrams]
            longest_anagram_length = length
    return longest_anagrams

def find_longest_anagrams_the_smart_way(word_dict):
    """
    Finds the longest anagrams in a list of words by putting them into bins
    by their sorted string form.  Returns the bins with the longest strings.

    Parameters:
    -----------
    word_list: string
        List to search for anagrams.

    Returns:
    --------
    longest_anagrams: list of list of strings
        Each inner list contains strings that are anagrams of each other.

    """
    word_dict = {}
    longest_anagrams = []
    anagram_length = 0
    for word in word_list:
        sorted_word = "".join(sorted(word))
        if not word_dict.get(sorted_word):
            word_dict[sorted_word] = [word]
        else:
            word_dict[sorted_word].append(word)
    for key in word_dict:
        if len(word_dict[key]) == 1:
            continue
        word_length = len(key)
        if word_length < anagram_length:
            continue
        elif word_length > anagram_length:
            longest_anagrams = [word_dict[key]]
            anagram_length = word_length
        elif word_length == anagram_length:
            longest_anagrams.append(word_dict[key])
    return longest_anagrams

print "Words with 'uu'", find_words_with_uu(word_list)

print "\nLetters that aren't doubled: ", find_letters_not_doubled(word_list)

print "\nLongest palindrome:", longest_palindrome(word_list)

print "\nWords with all vowels in order: ", find_words_with_all_vowels_in_order(word_list)

print "\nWords with all vowels: ", find_words_with_all_vowels(word_list)

print "\nLetter with most appearances in word: ", letter_with_most_appearances_in_word(word_list)

print "\nLongest anagrams: ", find_longest_anagrams_the_smart_way(word_list)
