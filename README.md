# MyTeams Protocol Specification
#### BY : GUY


## Commands

The MyTeams protocol supports the following commands:

- /help: show help
- /login ["username"]: set the user_name used by client
- /logout: disconnect the client from the server
- /users: get the list of all users that exist on the domain
- /user ["user_uuid"]: get information about a user
- /send ["user_uuid"] ["message_body"]: send a message to a user
- /messages ["user_uuid"]: list all messages exchanged with a user
- /subscribe ["team_uuid"]: subscribe to the event of a team and its subdirectories (enable reception of all events from a team)
- /subscribed? ["team_uuid"]: list all subscribed teams or list all users subscribed to a team
- /unsubscribe ["team_uuid"]: unsubscribe from a team
- /use? ["team_uuid"]? ["channel_uuid"]? ["thread_uuid"]: use specify a context team/channel/thread
- /create: based on what is being used create the subresource (see below)
- /list: based on what is being used list all the subresources (see below)
- /info: based on what is being used list the current (see below)
