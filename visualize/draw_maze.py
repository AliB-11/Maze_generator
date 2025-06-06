from PIL import Image, ImageDraw

N = 10          # Grid size
SIDE = 20       # Pixels per cell
MARGIN = 1      # Wall thickness

def load_mst(path):
    with open(path, 'r') as f:
        return [[int(x) for x in line.strip().split()] for line in f]

def draw_maze(mst, filename='maze.png'):
    PAD = SIDE  # 1 full cell of padding around the maze
    img_size = (N * SIDE) + 2 * PAD
    img = Image.new('RGB', (img_size, img_size), 'white')
    draw = ImageDraw.Draw(img)

    for row in range(N):
        for col in range(N):
            node = row * N + col
            x = PAD + col * SIDE
            y = PAD + row * SIDE

            # Draw cell as white square
            draw.rectangle([x, y, x + SIDE, y + SIDE], fill='white')

            # Draw walls
            if mst[node][0] == 0:  # TOP
                draw.line([x, y, x + SIDE, y], fill='black', width=MARGIN)
            if mst[node][1] == 0:  # LEFT
                draw.line([x, y, x, y + SIDE], fill='black', width=MARGIN)
            if mst[node][2] == 0:  # BOTTOM
                draw.line([x, y + SIDE, x + SIDE, y + SIDE], fill='black', width=MARGIN)
            if mst[node][3] == 0:  # RIGHT
                draw.line([x + SIDE, y, x + SIDE, y + SIDE], fill='black', width=MARGIN)

    img.save(filename)
    print(f"Saved maze image to {filename}")

if __name__ == '__main__':
    mst = load_mst("../output/mst.txt")

    # Carve entrance and exit
    mst[0][1] = 1           # open LEFT wall of start
    mst[N*N - 1][3] = 1     # open RIGHT wall of end
    
    draw_maze(mst)