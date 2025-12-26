
import PropTypes from 'prop-types';

const NameCard = ({ name }) => {
  return (
    <div className="card name-card">
      <div className="profile-image-container">
        <img 
          src="https://images.unsplash.com/photo-1535713875002-d1d0cf377fde?auto=format&fit=crop&w=800&q=80" 
          alt="Profile" 
          className="profile-image"
        />
      </div>
      <h2 className="card-title">Hello, I am</h2>
      <p className="card-name">{name}</p>
    </div>
  );
};

NameCard.propTypes = {
  name: PropTypes.string.isRequired,
};

export default NameCard;
