#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dog
{
	char *name;
	float age;
	char *owner;
} dog_t;

/**
 * Creates a new dog with the given name, age, and owner.
 * Returns a pointer to the new dog on success, or NULL on failure.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog = malloc(sizeof(dog_t));
	if (dog == NULL)
	{
	printf("Error: Failed to allocate memory for dog.\n");
	exit(1);
	}
	dog->name = malloc(strlen(name) + 1);
	if (dog->name == NULL)
	{
	printf("Error: Failed to allocate memory for name.\n");
	free(dog);
	exit(1);
	}
	strcpy(dog->name, name);

	dog->owner = malloc(strlen(owner) + 1);
		if (dog->owner == NULL)
		{
		printf("Error: Failed to allocate memory for owner.\n");
		free(dog->name);
		free(dog);
		exit(1);
		}
		strcpy(dog->owner, owner);

		dog->age = age;
	return dog;
}
