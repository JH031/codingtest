import re

def solution(files):
    def sort_key(filename):

        match = re.match(r'(\D+)(\d{1,5})(.*)', filename)
        
        head = match.group(1)
        number = match.group(2)
        
        return (head.lower(), int(number))

    return sorted(files, key=sort_key)