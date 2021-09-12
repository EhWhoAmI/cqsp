---
layout: post
title: "Ticks and dates"
date: 2021-09-11
categories: dev-diary
author: EhWhoAmI
---
A StarDate holds and calculates the tick that is on going. The tick is the number of hours that has been
ongoing since the start of the day. Here is some rough thinking for what interval things
should be done at.
 - 1 tick: Combat ticks, planetary and ship movement?
 - 25 ticks: (about a day) Economic activity, though I don't think it's such a good idea to put them in such a tight interval.
 - 25 * 5 = 125 ticks: (about 5 days)
 - 25 * 25 = 625 ticks: (about 26 days) Construction progress, pop growth, social changes, will also be the interval that would be used for the reference value
 - 25 ^ 3 / 2 ~= 15625 ticks: (about 312 days) Momentous things and things that take a long time, such as planet's climates changing

We will not do days and years, because these are specific to only earth, and we would like to
portray the different cultural differences resulting from different orbital periods and
rotational periods from planets, and it would be rather human-centric to assume other
civilizations would use our calendar. As a result, I plan to introduce a system that allows
the creation of different types of calendars. That would come later, though

However, this can bring some issues with statistics, because it can be hard for the player
to know how much they are gaining over some year, especially as we calculate over the period
that is irregular with a year. We can do that by calculating the ratio between the interval
and the calendar time. Not sure how well that would work though.
