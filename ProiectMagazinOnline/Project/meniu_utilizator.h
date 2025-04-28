#pragma once

// Declaratia meniului principal de dupa autentificare
// Ofera functionalitati: Lista Produse, Cos Cumparaturi, Finalizare Comanda, Vizualizare Comenzi
void meniuUtilizatorAutentificat();

// Declaratia functiei pentru incarcarea produselor din fisierul produse.txt
void incarcaProduseDinFisier(const std::string& numeFisier);
