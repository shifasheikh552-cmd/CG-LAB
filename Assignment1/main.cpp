#include <graphics.h>
#include <conio.h>
#include <iostream>

int main() {
    // Initialize graphics window (800 x 600)
    int screenWidth = 800;
    int screenHeight = 600;
    initwindow(screenWidth, screenHeight, "CGM Lab Assignment 1 - Basic Shapes");

    // Background styling
    setbkcolor(BLACK);
    cleardevice();

    // Title and Header
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(200, 20, (char*)"CGM LAB ASSIGNMENT - 1");

    setcolor(LIGHTGRAY);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(250, 48, (char*)"Basic Graphics Primitives: Line, Circle, Rectangle, Triangle");

    // Divider line below header
    setcolor(DARKGRAY);
    line(40, 70, 760, 70);

    // ==========================================
    // 1. STRAIGHT LINE
    // ==========================================
    setcolor(DARKGRAY);
    rectangle(45, 90, 385, 305);

    setcolor(YELLOW);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(60, 105, (char*)"1. Straight Line (line)");

    // Draw straight line from (x1, y1) to (x2, y2)
    setcolor(LIGHTCYAN);
    line(90, 245, 340, 150);

    // Endpoint indicators
    setcolor(LIGHTRED);
    circle(90, 245, 4);
    circle(340, 150, 4);

    setcolor(WHITE);
    outtextxy(75, 260, (char*)"P1(90, 245)");
    outtextxy(280, 135, (char*)"P2(340, 150)");

    // ==========================================
    // 2. CIRCLE
    // ==========================================
    setcolor(DARKGRAY);
    rectangle(415, 90, 755, 305);

    setcolor(YELLOW);
    outtextxy(430, 105, (char*)"2. Circle (circle)");

    setcolor(LIGHTMAGENTA);
    int xc = 585;
    int yc = 195;
    int r = 60;
    circle(xc, yc, r);

    // Center point and radius
    setcolor(LIGHTRED);
    circle(xc, yc, 3);
    setcolor(LIGHTGRAY);
    line(xc, yc, xc + r, yc);

    setcolor(WHITE);
    outtextxy(525, 268, (char*)"Center: (585, 195) | Radius: 60");

    // ==========================================
    // 3. RECTANGLE
    // ==========================================
    setcolor(DARKGRAY);
    rectangle(45, 325, 385, 545);

    setcolor(YELLOW);
    outtextxy(60, 340, (char*)"3. Rectangle (rectangle)");

    setcolor(LIGHTGREEN);
    // Draw rectangle: left, top, right, bottom
    rectangle(90, 385, 340, 495);

    setcolor(WHITE);
    outtextxy(75, 370, (char*)"(left, top) = (90, 385)");
    outtextxy(180, 505, (char*)"(right, bottom) = (340, 495)");

    // ==========================================
    // 4. TRIANGLE
    // ==========================================
    setcolor(DARKGRAY);
    rectangle(415, 325, 755, 545);

    setcolor(YELLOW);
    outtextxy(430, 340, (char*)"4. Triangle (using 3 lines)");

    // Triangle vertices
    int x1 = 585, y1 = 375;
    int x2 = 700, y2 = 495;
    int x3 = 470, y3 = 495;

    setcolor(LIGHTRED);
    // Connect 3 vertices to form triangle
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Vertices indicators
    setcolor(YELLOW);
    circle(x1, y1, 3);
    circle(x2, y2, 3);
    circle(x3, y3, 3);

    setcolor(WHITE);
    outtextxy(x1 - 35, y1 - 15, (char*)"A(585, 375)");
    outtextxy(x2 - 10, y2 + 10, (char*)"B(700, 495)");
    outtextxy(x3 - 30, y3 + 10, (char*)"C(470, 495)");

    // Save screenshot directly to disk
    writeimagefile((char*)"output.bmp");

    // Instruction prompt
    setcolor(WHITE);
    outtextxy(230, 565, (char*)"Press any key to close the graphics window...");

    // Wait for keypress
    getch();

    // Close graphics window
    closegraph();
    return 0;
}
