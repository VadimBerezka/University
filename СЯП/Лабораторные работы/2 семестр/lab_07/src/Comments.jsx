import React, { useState } from 'react';

const Comment = ({ comment, updateComment, deleteComment }) => {
  const [isEditing, setIsEditing] = useState(false);
  const [editedComment, setEditedComment] = useState(comment.text);

  const handleUpdate = () => {
    updateComment(comment.id, editedComment);
    setIsEditing(false);
  };

  const handleDelete = () => {
    const secretWord = prompt('Введите секретное слово для удаления комментария');
    if (secretWord === comment.secretWord) {
      deleteComment(comment.id);
    } else {
      alert('Неверное секретное слово');
    }
  };

  return (
    <div>
      <h3>{comment.username}</h3>
      <p>{isEditing ? <input value={editedComment} onChange={(e) => setEditedComment(e.target.value)} /> : comment.text}</p>
      {isEditing ? (
        <button onClick={handleUpdate}>Сохранить</button>
      ) : (
        <button onClick={() => setIsEditing(true)}>Изменить</button>
      )}
      <button onClick={handleDelete}>Удалить</button>
      <button onClick={() => alert(`Имя пользователя: ${comment.username}\nДата изменения: ${comment.date}\nEmail: ${comment.email}`)}>Просмотреть информацию</button>
    </div>
  );
};

const Comments = () => {
  const [comments, setComments] = useState([]);

  const addComment = (username, avatar, email, text, secretWord) => {
    const newComment = {
      id: Math.random(),
      username,
      avatar,
      email,
      text,
      secretWord,
      date: new Date().toISOString(),
    };
    setComments([...comments, newComment]);
  };

  const updateComment = (id, newText) => {
    setComments(comments.map((comment) => (comment.id === id ? { ...comment, text: newText, date: new Date().toISOString() } : comment)));
  };

  const deleteComment = (id) => {
    setComments(comments.filter((comment) => comment.id !== id));
  };

  return (
    <div>
      {comments.map((comment) => (
        <Comment key={comment.id} comment={comment} updateComment={updateComment} deleteComment={deleteComment} />
      ))}
    </div>
  );
};

export default Comments;
