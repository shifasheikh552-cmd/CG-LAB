#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <cmath>
#include <iomanip>

// Rounding helper function
int roundVal(float val) {
    return (int)(val + 0.5f);
}

// DDA Line Drawing Algorithm Implementation
void drawDDA(float x1, float y1, float x2, float y2, int color) {
    // Step 1: Calculate differences dx and dy
    float dx = x2 - x1;
    float dy = y2 - y1;

    // Step 2: Calculate steps = max(|dx|, |dy|)
    float steps = (std::abs(dx) > std::abs(dy)) ? std::abs(dx) : std::abs(dy);

    // Step 3: Calculate increment in x and y per step
    float xInc = dx / steps;
    float yInc = dy / steps;

    // Step 4: Initialize starting coordinates
    float x = x1;
    float y = y1;

    // Output calculation table to console
    std::cout << "\n------------------------------------------------------------\n";
    std::cout << " Step |    x    |    y    | Plotted (round(x), round(y))\n";
    std::cout << "------------------------------------------------------------\n";

    // Step 5: Plot pixels sequentially for each step
    for (int i = 0; i <= (int)steps; i++) {
        // Plot pixel using graphics primitive
        putpixel(roundVal(x), roundVal(y), color);
        // Slightly thicken for visibility on high-resolution displays
        putpixel(roundVal(x), roundVal(y) + 1, color);

        // Display sample steps in terminal
        if (i < 5 || i > (int)steps - 5 || (steps > 10 && i % ((int)steps / 5) == 0)) {
            std::cout << std::setw(5) << i << " | "
                      << std::fixed << std::setprecision(2) << std::setw(7) << x << " | "
                      << std::setw(7) << y << " | ("
                      << roundVal(x) << ", " << roundVal(y) << ")\n";
        } else if (i == 5) {
            std::cout << "  ... |   ...   |   ...   | ...\n";
        }

        // Increment coordinates
        x += xInc;
        y += yInc;
    }
    std::cout << "------------------------------------------------------------\n";
    std::cout << " Total steps executed: " << (int)steps << " (Total Pixels: " << (int)steps + 1 << ")\n";
}

int main() {
    float x1, y1, x2, y2;

    std::cout << "============================================================\n";
    std::cout << "   CGM LAB ASSIGNMENT 2: DDA Line Drawing Algorithm\n";
    std::cout << "============================================================\n";
    std::cout << "Enter starting point (x1 y1): ";
    if (!(std::cin >> x1 >> y1)) {
        x1 = 120;
        y1 = 440;
        std::cout << "120 440 (default)\n";
    }

    std::cout << "Enter ending point   (x2 y2): ";
    if (!(std::cin >> x2 >> y2)) {
        x2 = 680;
        y2 = 180;
        std::cout << "680 180 (default)\n";
    }

    // Mathematical parameters
    float dx = x2 - x1;
    float dy = y2 - y1;
    float steps = (std::abs(dx) > std::abs(dy)) ? std::abs(dx) : std::abs(dy);
    float xInc = dx / steps;
    float yInc = dy / steps;
    float slope = (dx != 0) ? (dy / dx) : 0;

    std::cout << "\nAlgorithm Summary:\n";
    std::cout << " dx = x2 - x1 = " << dx << "\n";
    std::cout << " dy = y2 - y1 = " << dy << "\n";
    std::cout << " Steps = max(|dx|, |dy|) = " << (int)steps << "\n";
    std::cout << " x_inc = dx / steps = " << xInc << "\n";
    std::cout << " y_inc = dy / steps = " << yInc << "\n";
    std::cout << " Slope (m) = " << slope << "\n";

    // Initialize graphics window (800 x 600)
    int screenWidth = 800;
    int screenHeight = 600;
    initwindow(screenWidth, screenHeight, "CGM Lab Assignment 2 - DDA Line Drawing Algorithm");

    setbkcolor(BLACK);
    cleardevice();

    // Title and Header
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(180, 20, (char*)"CGM LAB ASSIGNMENT - 2");

    setcolor(LIGHTGRAY);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(220, 50, (char*)"Digital Differential Analyzer (DDA) Line Algorithm");

    // Divider line
    setcolor(DARKGRAY);
    line(40, 75, 760, 75);

    // ==========================================
    // Outer Drawing Canvas Frame
    // ==========================================
    setcolor(DARKGRAY);
    rectangle(40, 90, 760, 540);

    // Subtle background grid
    setcolor(COLOR(30, 30, 40));
    for (int gx = 90; gx <= 710; gx += 50) {
        line(gx, 95, gx, 535);
    }
    for (int gy = 140; gy <= 490; gy += 50) {
        line(45, gy, 755, gy);
    }

    // ==========================================
    // Parameters Info Overlay Card (Top Left)
    // ==========================================
    setcolor(COLOR(20, 25, 35));
    setfillstyle(SOLID_FILL, COLOR(20, 25, 35));
    bar(55, 105, 370, 265);
    setcolor(LIGHTCYAN);
    rectangle(55, 105, 370, 265);

    setcolor(YELLOW);
    outtextxy(70, 115, (char*)"[ DDA Computation Parameters ]");

    char buffer[100];
    setcolor(WHITE);
    sprintf(buffer, "Start Point P1 : (%.0f, %.0f)", x1, y1);
    outtextxy(70, 138, buffer);

    sprintf(buffer, "End Point P2   : (%.0f, %.0f)", x2, y2);
    outtextxy(70, 158, buffer);

    setcolor(LIGHTGRAY);
    sprintf(buffer, "dx = %.0f,  dy = %.0f", dx, dy);
    outtextxy(70, 180, buffer);

    sprintf(buffer, "Steps = max(|dx|,|dy|) = %d", (int)steps);
    outtextxy(70, 200, buffer);

    sprintf(buffer, "x_inc = %.4f,  y_inc = %.4f", xInc, yInc);
    outtextxy(70, 220, buffer);

    sprintf(buffer, "Slope m = dy/dx = %.4f", slope);
    outtextxy(70, 240, buffer);

    // ==========================================
    // Execute DDA Line Drawing
    // ==========================================
    // Draw Primary Line in Cyan using DDA
    drawDDA(x1, y1, x2, y2, CYAN);

    // Mark Start Point P1
    setcolor(LIGHTRED);
    circle((int)x1, (int)y1, 5);
    setfillstyle(SOLID_FILL, LIGHTRED);
    fillellipse((int)x1, (int)y1, 3, 3);
    setcolor(YELLOW);
    sprintf(buffer, "P1 (%.0f, %.0f)", x1, y1);
    outtextxy((int)x1 - 20, (int)y1 + 12, buffer);

    // Mark End Point P2
    setcolor(LIGHTRED);
    circle((int)x2, (int)y2, 5);
    setfillstyle(SOLID_FILL, LIGHTRED);
    fillellipse((int)x2, (int)y2, 3, 3);
    setcolor(YELLOW);
    sprintf(buffer, "P2 (%.0f, %.0f)", x2, y2);
    outtextxy((int)x2 - 30, (int)y2 - 20, buffer);

    // Line Label
    setcolor(CYAN);
    outtextxy(420, 300, (char*)"<-- DDA Plotted Line (Pixel-by-Pixel)");

    // Bottom exit prompt
    setcolor(WHITE);
    outtextxy(240, 560, (char*)"Press any key to close the graphics window...");

    // Save screenshot directly to disk
    writeimagefile((char*)"output_dda.bmp");

    // Hold screen until key press
    getch();

    closegraph();
    return 0;
}
