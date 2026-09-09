blocs = ["756e505234376848", "45414a3561733951", "377a7143574e6758", "354a35686e475873", "48336750664b394d"]

mot_de_passe = ""

for bloc in blocs: # ex: bloc = 756e505234376848
    octets = bytes.fromhex(bloc) 
    print("octets:", octets) # ex: "756e505234376848" -> "unPR47hH"
    texte = octets[::-1].decode("ascii", errors="ignore")
    print("texte:", texte) # ex: "unPR47hH" -> "Hh74RPnu"
    mot_de_passe += texte # concatenation

print("pass :", mot_de_passe)