# include <stdio.h>
# include <stdlib.h>

# define ZINS 5.0

double berechne(double grundkapital, int jahr)
{
  if (jahr < 1) {
    printf("Fehler in berechne(...)! Der Anlagezeitraum darf nicht kleiner als 1 Jahr sein!");
    exit(EXIT_FAILURE);
  }
  if (grundkapital < 0) {
    printf("Fehler in berechne(...)! Das Grundkapital darf nicht negativ sein!");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < jahr; i++)
    grundkapital = grundkapital * (1 + (ZINS / 100));
  
  return grundkapital;
}

void erzeuge_kapital_liste(double grundkapital, int laufzeit, double kapital[])
{
  if (laufzeit < 1) {
    printf("Fehler in erzeuge_kapital_liste(...)! Der Anlagezeitraum darf nicht kleiner als 1 Jahr sein!");
    exit(EXIT_FAILURE);
  }
  if (grundkapital < 0) {
    printf("Fehler in erzeuge_kapital_liste(...)! Das Grundkapital darf nicht negativ sein!");
    exit(EXIT_FAILURE);
  }

  kapital[0] = grundkapital;
  for (int i = 1; i <= laufzeit; i++)
    kapital[i] = berechne(grundkapital, i);
}

void pretty_print(double grundkapital, int laufzeit, double kapital[])
{
  printf("Jahr\tKapital\n");
  for (int i = 0; i <= laufzeit; i++)
    printf("%d\t%.2f\n", i, kapital[i]);
}

int main()
{
  float grundkapital;
  int laufzeit;

  printf("Gib dein Startguthaben ein:\n");
  scanf("%f", &grundkapital);

  printf("Gib den Sparzeitraum an:\n");
  scanf("%d", &laufzeit);

  double kapital[laufzeit + 1];
  erzeuge_kapital_liste(grundkapital, laufzeit, kapital);
  pretty_print(grundkapital, laufzeit, kapital);
  
  return 0;
}
