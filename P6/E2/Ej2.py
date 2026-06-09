import cv2

# Cargamos el clasificador de caras
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_alt.xml')

#Abrimos el archivo de video
cap = cv2.VideoCapture("v3.mp4")

while True:
    #leemos cada fotograma
    ret, frame = cap.read()
    if not ret: break

    #aplicamos el detector (igual que en el Ej 1)
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    caras = face_cascade.detectMultiScale(gray, 1.3, 5)

    #dibujamos los rectángulos sobre el fotograma actual
    for (x, y, w, h) in caras:
        cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 0), 2)

    #enseñamos el vídeo en tiempo real
    cv2.imshow('Deteccion de caras', frame)

    #al pulsar q salimos del bucle
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# 6. Liberamos la cámara
cap.release()
cv2.destroyAllWindows()
