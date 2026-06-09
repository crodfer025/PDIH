library(audio)
library(tuneR)
library(seewave)
#Ej 2
#Carga de archivos
nombre <- readWave("nombre.wav")
apellido <- readWave("apellido.wav")

#Forma de onda
plot(apellido, main="Forma de onda: Apellido")
plot(nombre, main="Forma de onda: Nombre")

#Ej 3
#Info de Cabecera
str(nombre)
str(apellido)

#Ej 4
#unir sonidos
nombre_completo <- pastew(apellido, nombre, output="Wave")

#Ej 5
#dibujar
plot(nombre_completo, main="Forma de onda: Nombre Completo")
#oir
setWavPlayer("aplay")
listen(nombre_completo)

#Ej 6
#almacenar
writeWave(nombre_completo, "nombre_completo.wav")


#Ej 7
#UpSampling
nombre_44k <- resamp(nombre_completo, f=nombre_completo@samp.rate, g=44100, output="Wave")
#filtro
sonido_filtrado <- bwfilter(nombre_44k, f=44100, from=10000, to=20000, bandpass=FALSE, output="Wave")
#oir
listen(sonido_filtrado)
#forma de onda
plot(sonido_filtrado, main="Forma de onda: Nombre Completo Filtrado")


#Ej 8
#Eco
sonido_eco <- echo(nombre_completo, f=nombre_completo@samp.rate, amp=c(0.8, 0.4, 0.2), delay=c(1, 2, 3), output="Wave")
listen(sonido_eco)
writeWave(sonido_eco, "eco.wav")
#Del revés
sonido_al_reves <- revw(nombre_completo, output="Wave")
listen(sonido_al_reves)
writeWave(sonido_al_reves, "alreves.wav")
