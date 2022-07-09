/**
 * steps to include.
 * you ar allowed to copy this file as make changes to any section including this comment section.
 * im legit just brainstorming
 *
 *
 * the printk funtion prints arguments to output
 *      it prints in stages
 *          stage one: its returns elements to output
 *          stage two: if thers % its activates func.c file
 *                      func.c file would contain state() function and spec() function
 *          state() function would check if theres state mentioned the execute action
 *                  else ( just execute spec() function)
 *
 *          spec() and state() functions may include other functions in them or
 *              have to call the functions.
 *
 * essentially the main functions include
 *      main()
 *          {
 *              calls printk()
 *          }
 *
 * printk()
 *          {
 *              if (% = true)
 *              calls spec() &&
 *                    state()
 *          }
 * state()
 *          {
 *              calls all the state function()
 *          }
 * spec()
 *          {
 *              calls all specifier functions()
 *          }
 */
