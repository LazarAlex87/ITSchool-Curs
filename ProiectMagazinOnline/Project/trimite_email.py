# trimite_email.py
import smtplib
import ssl
import sys

def trimite_email(destinatar, mesaj):
    # Contul de pe care trimitem
    email_expeditor = "itschoolcpp@gmail.com"     
    parola_app = "tpuudjwwvglfurkk"            

    context = ssl.create_default_context()

    with smtplib.SMTP_SSL("smtp.gmail.com", 465, context=context) as server:
        server.login(email_expeditor, parola_app)
        server.sendmail(email_expeditor, destinatar, mesaj)

if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("Utilizare: python trimite_email.py email_destinatar tip mesaj")
        sys.exit(1)

    email_destinatar = sys.argv[1]
    tip = sys.argv[2]
    valoare = sys.argv[3]

    if tip == "cod":
        mesaj = f"Subject: Cod de Verificare\n\nCodul tau de verificare este: {valoare}"
    elif tip == "parola":
        mesaj = f"Subject: Parola Uitata\n\nParola ta este: {valoare}"
    else:
        mesaj = f"Subject: Mesaj Necunoscut\n\n{valoare}"

    trimite_email(email_destinatar, mesaj)

