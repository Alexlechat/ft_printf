# ft_printf

`ft_printf` est une ré-implémentation de la fonction standard `printf` en langage C.  
Ce projet m’a permis d’approfondir la gestion des pointeurs, la manipulation de chaînes, et le fonctionnement interne des fonctions variadiques.

## Objectifs pédagogiques

- Comprendre les fonctions variadiques (`stdarg.h`)
- Gérer l'affichage formaté de divers types
- Décomposer un parsing de format complexe
- Produire un code structuré, réutilisable et conforme à la norme 42

## Fonctionnalités implémentées

Ma version de `printf` prend en charge les spécificateurs suivants :

| Spécificateur | Description                       |
|---------------|-----------------------------------|
| `%c`          | Affiche un caractère              |
| `%s`          | Affiche une chaîne de caractères  |
| `%p`          | Affiche une adresse mémoire       |
| `%d` / `%i`   | Affiche un entier signé           |
| `%u`          | Affiche un entier non signé       |
| `%x` / `%X`   | Affiche en hexadécimal (min/maj)  |
| `%%`          | Affiche le caractère `%`          |

## Compilation

```bash
make        # Compile la librairie
make clean  # Supprime les fichiers objets
make fclean # Supprime les fichiers objets et l’archive libftprintf.a
make re     # Fclean + make
