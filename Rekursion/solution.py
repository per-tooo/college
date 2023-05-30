# TODO: Implementieren Sie die Funktion wie in der Aufgabenstellung beschrieben! 
# Nur rekursive Lösungen werden akzeptiert!

def transformToUppercase(s):
	if not s:
		return ""
	
	char = s[0]
	if 'a' <= char <= 'z':
		char = chr(ord(char) - 32)
  
	return char + transformToUppercase(s[1:])
