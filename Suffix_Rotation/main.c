/*
 #include <string.h>
 #include <stdio.h>
 #include <stdlib.h>
 int main(void) {
 char s[] = "jxofqjjepvgmh";
 short int length = (short int) strlen(s), i = 0, counter = 0;
 unsigned char minimum = s[0];
 short int minimumI = 0, j = 0, z = 0;
 //rotating suffix function
 for (i = 0; i < (length - 1); i++) {
 //checking for the least character in the suffix
 minimum = 250;
 for (z = i; z < length; z++) {
 if (s[z] < minimum) {
 minimum = s[z];
 minimumI = z;
 }
 }
 /////////////////////////////////////////end of checking minimum character
 if ((minimumI - i) < (length - minimumI)) {
 short int rotateFcount = (minimumI - i); // times of forward rotations
 while (rotateFcount > 0) {
 counter++;
 for (j = i; j < (length - 1); j++) {
 unsigned char temp = s[j];
 s[j] = s[j + 1];
 s[j + 1] = temp;
 }
 rotateFcount--;
 printf("%d- %s\n",counter,s);
 }
 } else {
 short int rotateBcount = (length - minimumI); // times of backward rotations
 while (rotateBcount > 0) {
 counter++;
 for (j = (length - 1); j > i; j--) {
 unsigned char temp = s[j];
 s[j] = s[j - 1];
 s[j - 1] = temp;
 }
 rotateBcount--;
 printf("%d- %s\n",counter,s);
 }
 }
 }
 printf("%d\n", counter);
 printf("%s\n", s);
 return 0;
 }

 */

/////////////////////////////////////// suffix_generation
/*
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 void generate_suffix(char * s, short int length, char * suffix_array[]) {
 short int i = 0, j = 0;
 for (i = (length - 1); i >= 0; i--) {
 suffix_array[(length - 1 - i)] = (char*) malloc((length - i));
 for (j = (length - i); j > 0; j--) {
 suffix_array[(length - 1 - i)][(length-i)-j] = s[(length - j)];
 }
 suffix_array[(length - 1 - i)][(length - i)] = '\0';
 }
 }

 int main(void) {
 char s[1000] = "abcdefghijklmno";
 short int length = strlen(s), i = 0;
 char* suffix_array[1000] = {NULL};
 generate_suffix(s, length, suffix_array);
 while (suffix_array[i] != NULL) {
 printf("%s\n", suffix_array[i]);
 i++;
 }
 return 0;
 }
 */
//////////////////////////////////////////////////////
/*catch the criminals Roy*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void) {
	unsigned int criminal_pos[5] = { 1, 4, 5, 6, 9 };
	unsigned int cop_pos[5] = { 0 };
	unsigned int wage = 10, no_criminals = 5, no_officers = 0;
	unsigned int i = 0, j = 0, k = 0;
	unsigned int min_total_salary = (no_criminals * wage), total_salary = 0,
			fuel_cost = 0;
	for (no_officers = 1; no_officers <= no_criminals; no_officers++) {
		if (no_officers == 1) {
			fuel_cost = criminal_pos[no_criminals - 1] - criminal_pos[0];
			fuel_cost *= fuel_cost;
			total_salary = (no_officers * wage) + fuel_cost;
			if (total_salary < min_total_salary)
				min_total_salary = total_salary;
		} else if (no_officers == no_criminals) {
			total_salary = (no_officers * wage);
			if (total_salary < min_total_salary)
				min_total_salary = total_salary;
		} else if (no_officers == 2) {
			k = no_criminals - 1;
			for (j = 0; j < k; j++) {
				fuel_cost = ((criminal_pos[j] - criminal_pos[0])
						* (criminal_pos[j] - criminal_pos[0]))
						+ ((criminal_pos[k] - criminal_pos[j + 1])
								* (criminal_pos[k] - criminal_pos[j + 1]));
				total_salary = fuel_cost + (no_officers * wage);
				if (total_salary < min_total_salary)
					min_total_salary = total_salary;
			}
		} else {
			if no. of cops between 3 and n-1
			int l = 0;
			k = no_criminals - 1;
			cop_pos[0] = criminal_pos[0]; // cop  no.0 is always starting @ zero
			for (j = 1; (j < no_officers); j++) {
				cop_pos[j] = criminal_pos[j]; //identifying where every cop will start
			}ending of the for loop responsible for changing cops positions
			cop_pos[no_officers] = criminal_pos[no_criminals - 1];
			total_salary = (no_officers * wage);
			/////////////////////////////////////////
			for (l = (no_officers - 1); l >= 0; l--) {
				for (j = l; j < no_criminals; j++) {
					cop_pos[l] = criminal_pos[j];
					/////////////////////////////////////////
					for (k = 1; k < no_officers; k++) {
						if ((cop_pos[k] == criminal_pos[k])
								&& (cop_pos[k - 1] == criminal_pos[k - 1])) {

						} else {
							total_salary += ((cop_pos[k] - cop_pos[k - 1])
									* (cop_pos[k] - cop_pos[k - 1]));

						}
					}ending the for loop responsible for adding the fuel costs for each cop
					if (cop_pos[no_officers - 1]
							!= criminal_pos[no_criminals - 1]) {
						total_salary += ((criminal_pos[no_criminals - 1]
								- cop_pos[no_officers - 1])
								* (criminal_pos[no_criminals - 1]
										- cop_pos[no_officers - 1]));
					}
					/////
					if (total_salary < min_total_salary) {
						min_total_salary = total_salary;
					}

				}
			}
		}

	}

	printf("%d\n", min_total_salary);
	return 0;
}
*/

/*
 {
 for (k = (no_criminals - 1); k > 0; k--) {
 for (j = 0; j < k; j++) {
 fuel_cost = (criminal_pos[k] - criminal_pos[j])
 * (criminal_pos[k] - criminal_pos[j]);
 total_salary = (no_officers * wage) + fuel_cost;
 printf("%d\n", total_salary);
 if (total_salary < min_total_salary) {
 min_total_salary = total_salary;
 }
 }
 }
 }
 */




///////////////////////////////
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i = 4;
    double d = 4.0;
    char s[] = "HackerRank ";
    int ii = 0;
    double dd = 0;
    char ss[500];
    ///////////////////
    scanf("%d",&ii);
    scanf("%lf",&dd);
    fflush(stdin);
    scanf("%[^\n]",ss);
    ///////////////// printing results
    printf("%d\n",(ii+i));
    printf("%0.1lf\n",(d+dd));
    printf("%s%s\n",s,ss);
    return 0;
}
