using RuleEngineLLD.Models;

namespace RuleEngineLLD.Utils;

/// <summary>
/// Utility class with static helper methods for expense operations.
/// In C#, static classes contain only static methods (similar to Java's static utility classes).
/// </summary>
public static class ExpenseUtils
{
    /// <summary>
    /// Checks if all expenses belong to the same trip.
    /// </summary>
    public static bool AreAllExpensesOfSameTrip(List<Expense> expenses)
    {
        if (expenses.Count == 0)
        {
            return true;
        }

        string tripId = expenses[0].TripId;
        foreach (var expense in expenses)
        {
            if (expense.TripId != tripId)
            {
                return false;
            }
        }
        return true;
    }
}

