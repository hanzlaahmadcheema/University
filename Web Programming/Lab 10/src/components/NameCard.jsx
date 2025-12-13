
import PropTypes from 'prop-types';

const NameCard = ({ name }) => {
  return (
    <div className="card name-card">
      <h2 className="card-title">Hello, I am</h2>
      <p className="card-name">{name}</p>
    </div>
  );
};

NameCard.propTypes = {
  name: PropTypes.string.isRequired,
};

export default NameCard;
