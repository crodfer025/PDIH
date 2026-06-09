import cv2

# Cargamos el clasificador
gato_cascade = cv2.CascadeClassifier('haarcascade_frontalcatface_extended.xml')

# Abrimos el vídeo
cap = cv2.VideoCapture('gatitos.mp4')

# Configuración de ventana antes del bucle
cv2.namedWindow('Deteccion de gatos', cv2.WINDOW_NORMAL)
cv2.resizeWindow('Deteccion de gatos', 800, 600)

while cap.isOpened():
    ret, img = cap.read()

    if not ret:
        break

    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    # Buscamos caras de gatos
    gatos = gato_cascade.detectMultiScale(gray, scaleFactor=1.2, minNeighbors=3)

    # Dibujamos rectángulos
    for (x, y, w, h) in gatos:
        cv2.rectangle(img, (x, y), (x+w, y+h), (255, 0, 0), 2)

    cv2.imshow('Deteccion de gatos', img)
    
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
