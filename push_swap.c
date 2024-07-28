/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:50:12 by asodor            #+#    #+#             */
/*   Updated: 2024/07/20 19:49:22 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Helper function to find the index of the maximum value in the stack
int find_max_index(t_stack *stack) {
    int max = stack->top->value;
    int max_index = 0;
    int current_index = 0;
    t_node *current = stack->top;

    while (current) {
        if (current->value > max) {
            max = current->value;
            max_index = current_index;
        }
        current = current->next;
        current_index++;
    }
    return max_index;
}

// Function to find the correct position in stack B for a value from stack A
int find_position_in_b(t_stack *b, int value) {
    if (b->size == 0)
        return 0;

    t_node *current = b->top;
    int position = 0;
    int b_max = find_max(b);
    int b_min = find_min(b);

    // If value is greater than max or smaller than min in B
    if (value > b_max || value < b_min)
        return find_max_index(b);

    // Find the correct position
    while (current->next) {
        if (value > current->value && value < current->next->value)
            return position + 1;
        current = current->next;
        position++;
    }

    return 0;
}

// Helper function to find the cheapest number to push
int find_cheapest_to_push(t_stack *a, t_stack *b) {
    int cheapest_index = 0;
    int cheapest_cost = INT_MAX;
    int a_size = a->size;
    int b_size = b->size;

    for (int i = 0; i < a_size; i++) {
        int cost = 0;
        int value = get_value_at(a, i);
        
        // Calculate cost to move this number to top of A
        cost += (i <= a_size / 2) ? i : a_size - i;
        
        // Calculate cost to move to correct position in B
        int b_position = find_position_in_b(b, value);
        cost += (b_position <= b_size / 2) ? b_position : b_size - b_position;
        
        // Add 1 for the pb operation
        cost++;

        if (cost < cheapest_cost) {
            cheapest_cost = cost;
            cheapest_index = i;
        }
    }
    return cheapest_index;
}

// Helper function to push the cheapest number
void push_cheapest(t_stack *a, t_stack *b) {
    int cheapest_index = find_cheapest_to_push(a, b);
    int a_size = a->size;

    // Move the cheapest number to the top of A
    if (cheapest_index <= a_size / 2) {
        while (cheapest_index > 0) {
            ra(a);
            cheapest_index--;
        }
    } else {
        while (cheapest_index < a_size) {
            rra(a);
            cheapest_index++;
        }
    }

    // Push to B and position correctly
    pb(a, b);
    position_in_b(b, b->top->value);
}

// Helper function to sort last three elements in stack A
void sort_three(t_stack *a) {
    int first = a->top->value;
    int second = a->top->next->value;
    int third = a->top->next->next->value;

    if (first > second && second < third && first < third)
        sa(a);
    else if (first > second && second > third)
    {
        sa(a);
        rra(a);
    }
    else if (first > second && second < third && first > third)
        ra(a);
    else if (first < second && second > third && first < third)
    {
        sa(a);
        ra(a);
    }
    else if (first < second && second > third && first > third)
        rra(a);
}

// Helper function to push back from B to A
void push_back_to_a(t_stack *a, t_stack *b) {
    while (b->size > 0) {
        int max_index = find_max_index(b);
        int b_size = b->size;

        if (max_index <= b_size / 2) {
            while (max_index > 0) {
                rb(b);
                max_index--;
            }
        } else {
            while (max_index < b_size) {
                rrb(b);
                max_index++;
            }
        }
        pa(a, b);
    }
}

// Helper function to do the final arrangement (bring minimum to top)
void final_arrangement(t_stack *a) {
    int min_index = find_min_index(a);
    int a_size = a->size;

    if (min_index <= a_size / 2) {
        while (min_index > 0) {
            ra(a);
            min_index--;
        }
    } else {
        while (min_index < a_size) {
            rra(a);
            min_index++;
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        return 0;
    }

    t_stack *a = init_stack();
    t_stack *b = init_stack();

    for (int i = 1; i < argc; i++) {
        if (!is_integer(argv[i])) {
            fprintf(stderr, "Error\n");
            free_stack(a);
            free_stack(b);
            return 1;
        }
        push(a, atoi(argv[i]));
    }

    if (has_duplicates(a)) {
        fprintf(stderr, "Error\n");
        free_stack(a);
        free_stack(b);
        return 1;
    }

    // Implement sorting logic here
    if (a->size > 3) {
        // Push first two elements to B
        pb(a, b);
        pb(a, b);

        // Push cheapest elements until only 3 remain in A
        while (a->size > 3) {
            push_cheapest(a, b);
        }

        // Sort the last three elements in A
        sort_three(a);

        // Push back from B to A
        push_back_to_a(a, b);

        // Final arrangement
        final_arrangement(a);
    } else if (a->size == 2 && a->top->value > a->top->next->value) {
        sa(a);
    } else if (a->size == 3) {
        sort_three(a);
    }

    free_stack(a);
    free_stack(b);
    return 0;
}