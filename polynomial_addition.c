// Program for addition of polynomial in C.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct PolyNode
{
	int coeff;
	int expo;
	struct PolyNode *next;
};

struct PolyNode *first1, *first2, *first3;

void prepare_poly(struct PolyNode *nnode, struct PolyNode *frst)
{
	// write the logic to insert nnode at last position
	// and refer 'frst' to have first-node of LL
	struct PolyNode *temp;
	temp = frst;

	while(temp->next != NULL)
	{
		temp = temp->next;
	};
	temp->next = nnode;

} // end of prepare_poly


void create_first_poly()
{
	int count, i, high_coeff;
	struct PolyNode *nn;

	printf("Enter Highest Exponent of your expression : ");
	scanf("%d", &high_coeff);

	i=high_coeff;
	while(i>=0)
	{
		nn = (struct PolyNode *) malloc( sizeof( struct PolyNode ) );
		nn->expo = i;
		nn->next = NULL;

		printf("Enter co-efficient of exponent %d : ", i);
		scanf("%d", &nn->coeff);
		i--;

		if(first1==NULL)
		{
			first1=nn;
		}
		else
		{
			prepare_poly(nn, first1);
		}
	}
}

void create_second_poly()
{
	int count, i, high_coeff;
	struct PolyNode *nn;

	printf("Enter Highest Exponent of your expression : ");
	scanf("%d", &high_coeff);

	i=high_coeff;
	while(i>=0)
	{
		nn = (struct PolyNode *) malloc( sizeof( struct PolyNode ) );
		nn->expo = i;
		nn->next = NULL;

		printf("Enter co-efficient of exponent %d : ", i);
		scanf("%d", &nn->coeff);
		i--;

		if(first2==NULL)
		{
			first2=nn;
		}
		else
		{
			prepare_poly(nn, first2);
		}
	}
}

void add_two_poly()
{
	// For ease, take the polynomial with high exponent/power as first polynomial.
	// traverse on both polynomials parallally
	// add the co-efficients of nodes where exponent/power is same
	// create nn and add it to third LL.
	while(first1->next && first2->next)
    {
        if(first1->expo > first2->expo)
        {
            first3->expo = first1->expo;
            first3->coeff = first1->coeff;
            first1 = first1->next;
        }
        else if(first1->expo < first2->expo)
        {
            first3->expo = first2->expo;
            first3->coeff = first2->coeff;
            first2 = first2->next;
        }
        else
        {
            first3->expo = first1->expo;
            first3->coeff = first1->coeff + first2->coeff;
            first1 = first1->next;
            first2 = first2->next;
        }

        first3->next = (struct PolyNode *) malloc( sizeof( struct PolyNode ) );
        first3 = first3->next;
        first3->next = NULL;

    while(first1->next || first2->next)
    {
        if(first1->next)
        {
            first3->expo = first1->expo;
            first3->coeff = first1->coeff;
            first1 = first1->next;
        }
        if(first2->next)
        {
            first3->expo = first2->expo;
            first3->coeff = first2->coeff;
            first2 = first2->next;
        }
        first3->next = (struct PolyNode *) malloc( sizeof( struct PolyNode ) );
        first3 = first3->next;
        first3->next = NULL;
    }
    }
}

void display_poly(struct PolyNode *frst)
{
	// display from frst---to--->NULL
	while(frst != NULL)
    {
        printf("%dx^%d",frst->coeff, frst->expo);
        frst = frst->next;

        if(frst != NULL)
        {
            printf(" + ");
        }
    }
}

int main()
{
	first1 = NULL;
	first2 = NULL;
	first3 = NULL;

	printf("\nPreparing First Polynomial Equation\n");
	create_first_poly();

	printf("\nPreparing Second Polynomial Equation\n");
	create_second_poly();

	printf("\nShowing First Polynomial\n");
	display_poly(first1);

	printf("\nShowing Second Polynomial\n");
	display_poly(first2);

    first3 = (struct PolyNode *) malloc( sizeof( struct PolyNode ) );
	add_two_poly();

	printf("\nShowing Resulting Polynomial\n");
	display_poly(first3);

	return 0;
}
