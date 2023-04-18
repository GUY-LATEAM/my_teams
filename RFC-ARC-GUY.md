# MyTeams Protocol Specification
RFC: ARC-GUY

## 1. Introduction

This document describes the MyTeams protocol, which is designed to facilitate communication and collaboration within teams through a server-client architecture. The protocol supports a range of features, including user authentication, team and channel management, thread and comment creation, and personal messaging.

---

## 2. Terminology

- **Server**: The central component that manages the communication between clients and maintains the application state.
- **Client**: An endpoint that connects to the server to interact with the MyTeams application.
- **Team**: A group of users collaborating on a specific project or topic.
- **Channel**: A subcategory within a team that focuses on a particular aspect of the team's project or topic.
- **Thread**: A conversation within a channel, consisting of an initial post and additional comments.
- **Comment**: A message in response to a thread's initial post or another comment.
- **EndL**: The endl is a predefined object of ostream class. It is used to insert a new line characters and flushes the stream.

---

## 3. Architecture

The MyTeams protocol is built on a client-server architecture using TCP sockets for communication. The server maintains the application state, including users, teams, channels, threads, and comments. Clients connect to the server to send commands and receive updates, so it's important for the client to retain the context in order to send it for certain commands that will be explained later.

---

## 4. Data Model

The data model consists of the following structures:

- User: Contains user-related information, such as UUID, username, and connection status.
- Team: Contains team-related information, such as UUID, name, and description.
- Channel: nelContains chan-related information, such as UUID, name, and description.
- Thread: Contains thread-related information, such as UUID, title, and initial message.
- Comment: Contains comment-related information, such as UUID and message body.

---

## 5. Command and Response Format

Commands sent by the client follow the format in ASCII:

    <CMD><sp><args><endL>

- **CMD** : The command keyword (e.g., /login, /users, etc.).
- **sp** : A space separating the command keyword and its arguments.
- **args**: The command arguments, if any, enclosed in double quotes and separated by spaces (e.g., "username", "team_uuid").
- **endL** : The custom delimiter to indicate the end of the command, which is the sequence **\g\u\y**.

### 5.1 broadcast

    broadcast <type> <typeargs>

### 5.1.1 broadcast types

- **LOGIN**
- **LOGOUT**
- **TEAMS**
- **CHANNEL**
- **THREAD**
- **REPLY**
- **MESSAGE**

### 5.1.2 broadcast args

|  Types    | Format                                                            | Description                                                                                                                                    |
|-----------|-------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------|
| LOGIN     | "user_uuid:user_name"                                             | user_uuid: User's ID, user_name: User's name (logged in)                                                                                       |
| LOGOUT    | "user_uuid:user_name"                                             | user_uuid: User's ID, user_name: User's name (logged out)                                                                                      |
| MESSAGE   | "user_uuid:message_body"                    ,                     | user_uuid: Sender's ID, message_body: Private message content                                                                                  |
| THREAD    | "team_uuid:thread_uuid:user_uuid:reply_body"                      | team_uuid: Team's ID, thread_uuid: Thread's ID, user_uuid: User's ID (reply), reply_body: Reply content                                        |
| TEAMS     | "team_uuid:team_name:team_description"                            | team_uuid: Team's ID, team_name: Team's name, team_description: Team's description                                                             |
| CHANNEL   | "channel_uuid:channel_name:channel_description"                   | channel_uuid: Channel's ID, channel_name: Channel's name, channel_description: Channel's description                                           |
| REPLY     | "thread_uuid:user_uuid:thread_timestamp:thread_title:thread_body" | thread_uuid: Thread's ID, user_uuid: User's ID (thread), thread_timestamp: Timestamp, thread_title: Thread's title, thread_body: Thread's body |
| SUBSCRIBE | "user_uuid":"team_uuid"                                           | user_uuid: User's ID, team_uuid: Team's ID                                                                                                     |

#### 5.2 login
**login** "username" -> The username the client will use.

#### 5.3 logout
**logout** -> The client will disconnect from the server.

#### 5.4 users
**users** -> The server will send a list of all users.

#### 5.5 user
**user** "user_uuid" -> The server will send information about the user with the specified UUID.

#### 5.6 send
**send** "user_uuid" "message_body" -> The server will send a message to the user with the specified UUID.

#### 5.7 messages
**messages** "user_uuid" -> The server will send a list of all messages exchanged with the user with the specified UUID.

#### 5.8 subscribe
**subscribe** "team_uuid" -> The server will subscribe the client to the team with the specified UUID.

#### 5.9 subscribed
**subscribed** "team_uuid" -> The server will send a list of all users subscribed to the team with the specified UUID, if no team_uuid is entered, the server will list all subscribed teams.

#### 5.10 unsubscribe
**unsubscribe** "team_uuid" -> The server will unsubscribe the client from the team with the specified UUID.

#### 5.11 use
**use** "team_uuid:channel_uuid:thread_uuid" -> The server will use the team, channel, and thread with the specified UUIDs as the context for the following commands.

#### 5.12 create
**create** "team_uuid:channel_uuid:thread_uuid" "name" "description" -> The server will create a team, channel, or thread with the specified name and description in the context specified by the UUIDs.

#### 5.13 list
**list** "team_uuid:channel_uuid:thread_uuid" -> The server will send a list of all teams, channels, or threads in the context specified by the UUIDs.

#### 5.14 info
**info** "team_uuid:channel_uuid:thread_uuid" -> The server will send information about the team, channel, or thread in the context specified by the UUIDs.

The context for the use, create, list, and info commands is a string in the format "team_uuid:channel_uuid:thread_uuid". The server must use these UUIDs to determine the context in which the command should be executed.


### Responses from the server follow the format in ASCII:

    <STATUS><sp><CODE><sp><MESSAGE><endL>

- **STATUS**: The status of the response,indicate the success or failure of the command (OK, ERROR).
- **sp**: A space used to separate the response elements.
- **CODE**: A code corresponding to the message type or the specific message being sent.
- **MESSAGE**: The actual message content or information being sent as a response.

**CODE** :

Response codes are three-digit numeric codes used to indicate the outcome of a command. Response codes are grouped into five classes, based on the first digit of the code:

    1xx (Informational): The request was received, and the server continues to process it.
    2xx (Successful): The request was successfully received, understood, and accepted.
    3xx (Redirection): Additional action needs to be taken to complete the request.
    4xx (Client Error): The request contains bad syntax or cannot be fulfilled by the server.
    5xx (Server Error): The server failed to fulfill an apparently valid request.

Here are the response codes for ARC-GUY protocol:

    200 OK: The command was successfully processed.
    201 Created: The resource was successfully created (e.g., a team, channel, or thread).
    204 No Content: The command was successfully processed, but there is no data to return (e.g., upon logout).
    400 Bad Request: The received command is malformed or invalid.
    401 Unauthorized: The client needs to authenticate before performing this action.
    403 Forbidden: The client does not have the necessary permissions to perform this action.
    404 Not Found: The requested resource was not found (e.g., a user, team, channel, or thread).
    409 Conflict: The request could not be completed due to a conflict with the current state of the resource (e.g., the resource already exists).
    500 Internal Server Error: An error occurred on the server side while processing the command.

---

## 6. Error Handling

Errors in the MyTeams protocol are handled by returning an error code (e.g., 84) and an error message on the standart output as the libmyteams.so is using stderr. Clients should handle these errors appropriately.

---

## 7. Security

While password authentication is not required for this project, developers should implement basic security measures, such as ensuring that only logged-in users can access certain features and preventing unauthorized access to teams, channels, and threads.

