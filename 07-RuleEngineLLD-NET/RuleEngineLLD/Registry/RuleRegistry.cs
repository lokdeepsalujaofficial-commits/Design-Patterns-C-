using RuleEngineLLD.Models;
using RuleEngineLLD.Services.Rules;
using RuleEngineLLD.Services.Rules.Impl;

namespace RuleEngineLLD.Registry;

/// <summary>
/// Central registry for all rules in the system.
/// Static class with static methods - acts as a configuration/setup class.
/// </summary>
public static class RuleRegistry
{
    /// <summary>
    /// Gets expense-type-specific rules.
    /// Dictionary maps ExpenseType to list of rules for that type.
    /// </summary>
    public static Dictionary<ExpenseType, List<IExpenseRule>> GetExpenseRulesRegistry()
    {
        var registry = new Dictionary<ExpenseType, List<IExpenseRule>>();

        // Restaurant expenses: max $75
        registry[ExpenseType.Restaurant] = new List<IExpenseRule>
        {
            new MaxAmountRule(75)
        };

        // Airfare expenses: disallowed
        registry[ExpenseType.Airfare] = new List<IExpenseRule>
        {
            new DisallowRule()
        };

        return registry;
    }

    /// <summary>
    /// Gets rules that apply to ALL expenses (regardless of type).
    /// </summary>
    public static List<IExpenseRule> GetAllExpenseRulesRegistry()
    {
        return new List<IExpenseRule>
        {
            new MaxAmountRule(200) // All expenses max $200
        };
    }

    /// <summary>
    /// Gets trip-level rules (rules that validate multiple expenses together).
    /// </summary>
    public static List<ITripRule> GetAllTripRulesRegistry()
    {
        return new List<ITripRule>
        {
            new TripTotalMaxRule(1000) // Trip total max $1000
        };
    }
}

/*
 * JSON representation of the above rules:
 * 
 * {
 *   "expenseLevelRules": [
 *     {
 *       "expenseType": "Restaurant",
 *       "rules": [
 *         {
 *           "type": "MaxAmount",
 *           "maxAmount": 75
 *         }
 *       ]
 *     },
 *     {
 *       "expenseType": "Airfare",
 *       "rules": [
 *         {
 *           "type": "Disallow"
 *         }
 *       ]
 *     }
 *   ],
 *   "allExpenseRules": [
 *     {
 *       "type": "MaxAmount",
 *       "maxAmount": 200
 *     }
 *   ],
 *   "tripRules": [
 *     {
 *       "type": "TripTotalMax",
 *       "maxAmount": 1000
 *     }
 *   ]
 * }
 */

