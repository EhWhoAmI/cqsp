---
layout: post
title: "Economy Work as of October 2021"
date: 2021-10-20
categories: ["dev-diary"]
tags: ["dev-diary"]
author: EhWhoAmI
---
These few weeks have been more productive than expected, so here's a summary of what we did in the economy over this time.

The economy now is kinda functioning. Although it's not balanced, it has all the bits and pieces that we need to create a more complex economy. 

We added the ability for factories to buy and sell goods, and subsequently, the price will also rise and fall based on the supply and demand.
This was achieved by adding a ledger for the price, and incrementing the price of the supply was lower than the demand, and decreasing the price if the supply was higher than the demand.
Although this vaguely models a supply and demand system, a more sensitive and adaptable system that didn't change at a fixed rate would be nice.

Next, we also added the capability for factories to increase and decrease their production based on supply and demand in [#61](https://github.com/EhWhoAmI/cqsp/pull/61).
Factories will reduce their production if there is a surplus of resources in the market, and increase their production if their is a deficit.
However this system is not only executed in the wrong order, it is also not well done, and so the production of factories just drop to zero over time. This will have to change.

### Next steps
 - More adaptable supply and demand system that takes into account the difference in supply and demand
 - More goods and supply chains
 - Population will have to be properly paid based on their labor
 - economy has to be self sufficient, and self balancing, and will automatically become so, no matter what kinds of demand or supplies we place on it
