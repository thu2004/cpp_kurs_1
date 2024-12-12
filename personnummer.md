## C++-program som validerar ett svenskt personnummer

Skriver ett c++ program som ta in en person nummer i form av en sträng och avgöra om  det är en giltig svensk personnummer

### Formatkontroll:

* Validerar att personnumret har rätt längd och struktur
* Accepterar bara format som YYYYMMDD-XXXX


### Datumvalidering:

* Kontrollerar att månad är mellan 1-12
* Validerar dagantal för respektive månad (31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31)
* 4 sista XXXX bara består av siffror
  
### Några exempelkörningar:

* 19900101-1234 (giltig)
* 20100229-AA34 (ogiltig)
* 20230230 1234 (ogiltig)
* 201210-1234 (ogiltig)
