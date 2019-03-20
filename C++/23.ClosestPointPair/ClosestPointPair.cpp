#include <vector>
#include <algorithm>
#include <minmax.h>

using namespace std;

typedef pair<double, double> coordinate;
enum isValid {Find, NoFind};

isValid check = Find;

bool comp_x(const coordinate &coord1, const coordinate &coord2) {
	return coord1.first < coord2.first;
}

double getDistanceSquare(const coordinate &coord1, const coordinate &coord2) {
	double dx = coord1.first - coord2.first,
		dy = coord1.second - coord2.second;
	return sqrt(dx * dx + dy * dy);
}

double getClosestDistanceOneSection(vector<coordinate> &points, int l, int r) {
	if (l >= r) {
		return DBL_MAX;
	}
	if (l == r - 1) {
		return getDistanceSquare(points[l], points[r]);
	}
	int mid = (l + r) / 2;
	double dmin = min(getClosestDistanceOneSection(points, l, mid), getClosestDistanceOneSection(points, mid, r));
	int l_rec = l;
	double x_min = points[mid].first - dmin;
	if (points[l].first < x_min && mid - l > 1) {
		int l_x = l, r_x = mid;
		int mid_x;
		while (l_x <= r_x) {	
			mid_x = (l_x + r_x) / 2;
			if (points[mid_x].first < x_min) {
				l_x = mid_x + 1;
			}
			else if (points[mid_x].first > x_min){
				r_x = mid_x - 1;
			}
			else {
				break;
			}	

		}
		l_rec = l_x;
	}
	int r_rec = r;
	double x_max = points[mid].first + dmin;
	if (points[r].first > x_max && r - mid > 1) {
		int l_x = mid, r_x = r;
		int mid_x;
		while (l_x <= r_x) {		
			mid_x = (l_x + r_x) / 2;	
			if (points[mid_x].first < x_max) {
				l_x = mid_x + 1;
			}
			else if (points[mid_x].first > x_max) {
				r_x = mid_x - 1;
			}
			else {
				break;
			}	
		}
		r_rec = r_x;
	}
	for (int i = l_rec; i <= mid-1; ++i) {
		for (int j = mid+1; j <= r_rec; ++j) {
			double dist = getDistanceSquare(points[i], points[j]);
			if (dmin > dist) {
				dmin = dist;
			}
		}
	}
	return dmin;
}

double getClosestDistance_dacVer(vector<coordinate> &points) {
	if (points.size() < 2) {
		check = NoFind;
		return -1;
	}
	sort(points.begin(), points.end(), comp_x);
	return getClosestDistanceOneSection(points, 0, points.size()-1);
}
