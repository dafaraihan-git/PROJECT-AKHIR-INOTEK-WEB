import time
import requests
import serial

# 1. URL Firebase Realtime Database milikmu (ditambahkan .json di ujungnya)
FIREBASE_URL = "https://project-akhir-inotek-default-rtdb.asia-southeast1.firebasedatabase.app/status_lampu.json"

# 2. Konfigurasi Port Arduino
# Silakan cek di Arduino IDE kamu, ganti "COM3" sesuai dengan port Arduino yang terbaca
COM_PORT = "COM5" 
BAUD_RATE = 9600

print("=== JEMBATAN FIREBASE TO ARDUINO OLEH DAFA ===")

try:
    # Inisialisasi koneksi Serial ke Arduino
    arduino = serial.Serial(COM_PORT, BAUD_RATE, timeout=1)
    time.sleep(2) # Tunggu Arduino selesai berkomunikasi awal
    print(f"Status: Berhasil terhubung ke Arduino di {COM_PORT} ✅")
except Exception as e:
    print(f"Status: Gagal terhubung ke Arduino ❌\nError: {e}")
    print("\n[PENTING] Pastikan Arduino sudah dicolok dan COM Port di atas sudah disesuaikan!")
    exit()

last_status = None
print("Status: Memantau Firebase... Tekan Ctrl+C di CMD untuk berhenti.\n")

while True:
    try:
        # Ambil data terbaru dari Firebase
        response = requests.get(FIREBASE_URL)
        
        if response.status_code == 200:
            status_sekarang = response.json()
            
            # Jika ada perubahan angka di Firebase, kirim ke Arduino
            if status_sekarang != last_status:
                print(f"[Firebase Baru] status_lampu berubah menjadi: {status_sekarang}")
                
                # Kirim data angka + karakter newline (\n) ke Arduino
                data_kirim = f"{status_sekarang}\n"
                arduino.write(data_kirim.encode())
                
                print(f"[Serial Send] Mengirim '{status_sekarang}' ke Arduino via {COM_PORT}")
                last_status = status_sekarang
        else:
            print(f"Gagal membaca Firebase. Status code: {response.status_code}")
            
    except Exception as e:
        print(f"Koneksi terputus atau error: {e}")
        
    time.sleep(1) # Mengecek perubahan di Firebase setiap 1 detik