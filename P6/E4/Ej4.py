import cv2

# 1. Cargamos ambos clasificadores
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_alt.xml')
body_cascade = cv2.CascadeClassifier('haarcascade_fullbody.xml')

# 2. Abrimos el vídeo
cap = cv2.VideoCapture('v4.mp4') 

cv2.namedWindow('Deteccion: Cuerpos y Caras', cv2.WINDOW_NORMAL)
cv2.resizeWindow('Deteccion: Cuerpos y Caras', 800, 600)

while cap.isOpened():
    ret, img = cap.read()
    if not ret: break

    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    # 3. Detectamos ambos por separado
    caras = face_cascade.detectMultiScale(gray, 1.1, 5)
    cuerpos = body_cascade.detectMultiScale(gray, 1.1, 3)

    # 4. Dibujamos los rectángulos (usamos colores diferentes para diferenciar)
    for (x, y, w, h) in caras:
        cv2.rectangle(img, (x, y), (x+w, y+h), (0, 255, 0), 2) # Verde: Cara
    
    for (x, y, w, h) in cuerpos:
        cv2.rectangle(img, (x, y), (x+w, y+h), (255, 0, 0), 2) # Azul: Cuerpo

    cv2.imshow('Deteccion: Cuerpos y Caras', img)
    if cv2.waitKey(1) & 0xFF == ord('q'): break

cap.release()
cv2.destroyAllWindows()
