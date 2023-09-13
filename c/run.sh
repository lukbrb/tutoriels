FILE=build/pendu.o

if [ -f "$FILE" ]; then
    $FILE

else 
    echo "[x] L'executable $FILE n'existe pas."
    echo "[+] Essai de compilation..."
    ./build.sh
fi

if [ -f "$FILE" ]; then
    echo "[+] Compilation réussie !"
    echo ""
    echo ""
    $FILE

else 
    echo "[x] L'executable $FILE n'existe pas."
    echo "[x] La compilation a échoué..."
fi
