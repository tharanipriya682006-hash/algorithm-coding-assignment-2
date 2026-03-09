#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <float.h>
using namespace std;

struct Point {
    double x, y;
};

// Function to compute Euclidean distance between two points
double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}

// Brute-force method for small sets of points
double bruteForce(vector<Point>& points, int left, int right) {
    double minDist = DBL_MAX;
    for (int i = left; i < right; i++) {
        for (int j = i + 1; j <= right; j++) {
            double d = distance(points[i], points[j]);
            if (d < minDist)
                minDist = d;
        }
    }
    return minDist;
}

// Find the minimum distance across the "strip" area
double stripClosest(vector<Point>& strip, double d) {
    double minDist = d;
    sort(strip.begin(), strip.end(), [](Point a, Point b) { return a.y < b.y; });

    for (int i = 0; i < strip.size(); i++) {
        for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDist; j++) {
            double dist = distance(strip[i], strip[j]);
            if (dist < minDist)
                minDist = dist;
        }
    }
    return minDist;
}

// Recursive divide and conquer function
double closestUtil(vector<Point>& points, int left, int right) {
    // Base case: use brute force when small
    if (right - left <= 3)
        return bruteForce(points, left, right);

    int mid = (left + right) / 2;
    Point midPoint = points[mid];

    // Recursively find the smallest distances in left and right halves
    double dLeft = closestUtil(points, left, mid);
    double dRight = closestUtil(points, mid + 1, right);

    double d = min(dLeft, dRight);

    // Build the strip region (points close to the dividing line)
    vector<Point> strip;
    for (int i = left; i <= right; i++) {
        if (fabs(points[i].x - midPoint.x) < d)
            strip.push_back(points[i]);
    }

    // Return the overall minimum distance
    return min(d, stripClosest(strip, d));
}

// Wrapper function
double closestPair(vector<Point>& points) {
    // Sort points by x-coordinate initially
    sort(points.begin(), points.end(), [](Point a, Point b) { return a.x < b.x; });
    return closestUtil(points, 0, points.size() - 1);
}

int main() {
    vector<Point> points = {
        {2.1, 3.2}, {12.0, 30.0}, {40.0, 50.0}, {5.0, 1.0}, {12.0, 10.0}, {3.0, 4.0}
    };

    double minDist = closestPair(points);
    cout << "The smallest distance is: " << minDist << endl;

    return 0;
}
