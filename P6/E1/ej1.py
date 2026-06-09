import cv2

#Cargamos el modelo preentrenado
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_alt.xml')

#leemos la imagen
img = cv2.imread('imagen_input.jpg')

#convertimos la matriz de la imagen a escala de grises
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

#ejecuto el algoritmo de detección de rostros
caras = face_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5, minSize=(30, 30))

#Iterar sobre las coordenadas devueltas y dibujar rectángulos
for (x, y, w, h) in caras:
    cv2.rectangle(img, (x, y), (x+w, y+h), (0, 255, 0), 2)

#muestro el resultado por pantalla y guardarlo
cv2.imshow('Deteccion de Caras', img)
cv2.waitKey(0) # Espera a que el usuario pulse una tecla
cv2.destroyAllWindows()

# Guardar la imagen procesada
cv2.imwrite('resultado_ejercicio1.jpg', img)
