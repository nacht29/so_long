sudo apt-get update -y
sudo apt-get upgrade -y
sudo apt install libx11-dev -y
sudo apt install libxext-dev -y
sudo apt install libbsd-dev -y
sudo apt install clang -y

# GPU Server
# 1. Install packages
sudo apt-get update
sudo apt-get upgrade -y
sudo apt-get install -y xvfb x11vnc fluxbox novnc websockify

# 2. Start a virtual X server (display :100) with a 1536x864 screen
Xvfb :100 -screen 0 1536x864x24 &

# 3. Point GUI apps at the virtual display
export DISPLAY=:100

# 4. Start a lightweight window manager on that display
fluxbox &

# 5. Start a VNC server that mirrors the virtual display
x11vnc -display :100 -forever -shared -nopw -rfbport 5900 &

# 6. Start noVNC (websocket proxy + web UI) on port 6080
websockify --web=/usr/share/novnc 6081 localhost:5900 &

# 7. Run the programme
# cd /workspaces/codespace/so_long
# ./so_long assets/maps/valid_bonus/map_valid_big.ber